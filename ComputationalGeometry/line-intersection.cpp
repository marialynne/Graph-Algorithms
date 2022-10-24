#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <string>
using namespace std;

class Coordinate
{
public:
  pair<float, float> point;
  string identifier;

  Coordinate()
  {
    this->point = {0, 0};
    this->identifier = " ";
  }

  Coordinate(pair<float, float> _point, char _identifier)
  {
    this->point = _point;
    this->identifier = _identifier;
  }
};

class Line
{
public:
  Coordinate p1;
  Coordinate p2;

  Line(pair<float, float> point1, char point1Identifier, pair<float, float> point2, char point2Identifier)
  {
    Coordinate coordinate1 = Coordinate(point1, point1Identifier);
    Coordinate coordinate2 = Coordinate(point2, point2Identifier);

    if (point1.second > point2.second)
    {
      this->p1 = coordinate1;
      this->p2 = coordinate2;
    }
    else
    {
      this->p2 = coordinate1;
      this->p1 = coordinate2;
    }
  }
};

class Graph
{
public:
  vector<Line> segments;
  vector<Line> segmentsToCheck;
  vector<int> steps;
  map<string, set<string>> checkedLines;

  void getSteps()
  {
    for (auto i : this->segments)
    {
      this->steps.push_back(i.p1.point.second);
      this->steps.push_back(i.p2.point.second);
    }
    sort(this->steps.begin(), this->steps.end(), [](const int &a, const int &b) -> bool
         { return a > b; });

    vector<int>::iterator it = unique(this->steps.begin(), this->steps.end());

    this->steps.resize(distance(this->steps.begin(), it));
  }

  void searchForIntersection()
  {
    for (int line1 = 0; line1 < segmentsToCheck.size(); line1++)
    {
      for (int line2 = 0; line2 < segmentsToCheck.size(); line2++)
      {
        if (line1 != line2)
        {
          Line tempLine1 = this->segmentsToCheck[line1];
          Line tempLine2 = this->segmentsToCheck[line2];
          string line1_id = tempLine1.p1.identifier + tempLine1.p2.identifier;
          string line2_id = tempLine2.p1.identifier + tempLine2.p2.identifier;

          if (checkedLines[line1_id].find(line2_id) == checkedLines[line1_id].end())
          {
            checkedLines[line1_id].insert(line2_id);
            checkedLines[line2_id].insert(line1_id);
            cout << tempLine1.p1.identifier << tempLine1.p2.identifier << " " << tempLine2.p1.identifier << tempLine2.p2.identifier << " " << intersect(tempLine1, tempLine2) << endl;
          }
        }
      }
    }
  }

  void sweepingLine()
  {
    getSteps();
    set<string> linesWithoutComparison; // Lines que no se comparan porque estan solas en esa parte del sweeping line.
    cout << "\nIntersections: " << endl;

    for (int stepAtY : this->steps)
    {
      for (int index = 0; index < this->segments.size(); index++)
      {
        Line line = this->segments[index];
        string line_id = line.p1.identifier + line.p2.identifier;

        if (line.p1.point.second == stepAtY)
        {
          this->segmentsToCheck.push_back(line);
          searchForIntersection();
        }
        if (line.p2.point.second > stepAtY)
        {
          vector<Line>::iterator it;
          it = find_if(this->segmentsToCheck.begin(), this->segmentsToCheck.end(), [line](Line const &nextLine)
                       { return nextLine.p1.identifier == line.p1.identifier && nextLine.p2.identifier == line.p2.identifier; });
          if (it != this->segmentsToCheck.end())
            this->segmentsToCheck.erase(it);
          if (checkedLines[line_id].empty())
            linesWithoutComparison.insert(line_id);
        }
        if (line.p2.point.second == stepAtY && checkedLines[line_id].empty())
          linesWithoutComparison.insert(line_id);
      }
    }

    for (string line : linesWithoutComparison)
    {
      cout << line << " \tDoes not intersect with any line \n";
    }
  }

  void insertLine(pair<float, float> point1, char point1Identifier, pair<float, float> point2, char point2Identifier)
  {
    this->segments.push_back(Line(point1, point1Identifier, point2, point2Identifier));

    sort(this->segments.begin(), this->segments.end(), [](Line &a, Line &b) -> bool
         { return a.p1.point.second > b.p1.point.second; });
  }

  void print(vector<Line> segments)
  {
    cout << "\nYour given lines are: " << endl;
    for (auto i : segments)
      cout << i.p1.identifier << ": (" << i.p1.point.first << ", " << i.p1.point.second << ")\t" << i.p2.identifier << ": (" << i.p2.point.first << ", " << i.p2.point.second << ") " << endl;
  }

  bool checkSegment(pair<int, int> point1, pair<int, int> point2, pair<int, int> point3)
  {
    return (point3.first <= max(point1.first, point2.first) && point3.first >= min(point1.first, point2.first) &&
            point3.second <= max(point1.second, point2.second) && point3.second >= min(point1.second, point2.second));
  }

  int orientation(pair<int, int> point1, pair<int, int> point2, pair<int, int> point3)
  {
    int orientation = ((point3.first - point1.first) * (point2.second - point1.second)) - ((point2.first - point1.first) * (point3.second - point1.second));

    if (orientation == 0)
      return 0;

    return (orientation > 0) ? 1 : 2;
  }

  bool intersect(Line line1, Line line2)
  {
    int line1toLine2_p1_Orientation = orientation(line1.p1.point, line1.p2.point, line2.p1.point);
    int line1toLine2_p2_Orientation = orientation(line1.p1.point, line1.p2.point, line2.p2.point);
    int line2toLine1_p1_Orientation = orientation(line2.p1.point, line2.p2.point, line1.p1.point);
    int line2toLine1_p2_Orientation = orientation(line2.p1.point, line2.p2.point, line1.p2.point);

    if (line1toLine2_p1_Orientation != line1toLine2_p2_Orientation && line2toLine1_p1_Orientation != line2toLine1_p2_Orientation)
      return true;

    if (line1toLine2_p1_Orientation == 0 && checkSegment(line1.p1.point, line1.p2.point, line2.p1.point))
      return true;
    if (line1toLine2_p2_Orientation == 0 && checkSegment(line1.p1.point, line1.p2.point, line2.p2.point))
      return true;
    if (line2toLine1_p1_Orientation == 0 && checkSegment(line2.p1.point, line2.p2.point, line1.p1.point))
      return true;
    if (line2toLine1_p2_Orientation == 0 && checkSegment(line2.p1.point, line2.p2.point, line1.p2.point))
      return true;

    return false;
  };
};

vector<Line> getData()
{
  // YA NO ENTENDI COMO RECIBIR DATOS - DLV
  vector<Line> lines;
  int numberLines;

  cout << "Ingresa un numero multiplo de 4"
       << "\n";
  cin >> numberLines;

  return lines;
};

int main()
{

  Graph myGraph;
  myGraph.insertLine({-6, 4}, 'A', {-5, 0}, 'B');
  myGraph.insertLine({-1, 0}, 'C', {-4, 2}, 'D');
  myGraph.insertLine({-6, -4}, 'E', {-4, -2}, 'F');
  myGraph.insertLine({-5, 7}, 'G', {-4, 4}, 'H');
  myGraph.insertLine({1, 7}, 'I', {-6, 3}, 'J');
  myGraph.insertLine({-2, 6}, 'K', {1, 3}, 'L');
  myGraph.insertLine({2, -1}, 'M', {2, 2}, 'N');
  myGraph.insertLine({2, 1}, 'O', {2, 4}, 'P');
  myGraph.insertLine({-2, 12}, 'Q', {-2, 10}, 'R');
  myGraph.print(myGraph.segments);
  myGraph.sweepingLine();
};
