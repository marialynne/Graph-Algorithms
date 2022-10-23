#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;

class Coordinate
{
public:
  pair<float, float> point;
  char identifier;

  Coordinate()
  {
    this->point = {0, 0};
    this->identifier = ' ';
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
  vector<int> setps;
  set<pair<Line, Line>> intersections;

  void getSteps()
  {
    for (auto i : this->segments)
    {
      this->setps.push_back(i.p1.point.second);
      this->setps.push_back(i.p2.point.second);
    }
    sort(this->setps.begin(), this->setps.end(), [](const int &a, const int &b) -> bool
         { return a > b; });

    vector<int>::iterator it = unique(this->setps.begin(), this->setps.end());

    this->setps.resize(distance(this->setps.begin(), it));
  }

  void searchForIntersection()
  {
    if (this->segmentsToCheck.size() <= 1)
      return;

    for (int line1 = 0; line1 < segmentsToCheck.size(); line1++)
    {
      for (int line2 = 0; line2 < segmentsToCheck.size(); line2++)
      {
        if (line1 != line2)
        {
          // if (intersect(this->segmentsToCheck[line1], this->segmentsToCheck[line2]))
          Line tempLine1 = this->segmentsToCheck[line1];
          Line tempLine2 = this->segmentsToCheck[line2];
          cout << tempLine1.p1.identifier << tempLine1.p2.identifier << " " << tempLine2.p1.identifier << tempLine2.p2.identifier << " " << intersect(tempLine1, tempLine2) << endl;
          // this->intersections.insert(make_pair(tempLine1, tempLine2));
        }
      }
    }
  }

  void sweepingLine()
  {
    getSteps();

    for (int stepAtY : this->setps)
    {
      for (auto line : this->segments)
      {
        if (line.p1.point.second == stepAtY)
        {
          this->segmentsToCheck.push_back(line);
          searchForIntersection();
        }
      }

      for (auto line : this->segments)
      {
        if (line.p2.point.second == stepAtY)
        {
          vector<Line>::iterator it = find(this->segmentsToCheck.begin(), this->segmentsToCheck.end(), line);
          this->segmentsToCheck.erase(it);
        }
      }
    }
  }

  void insertLine(pair<float, float> point1, char point1Identifier, pair<float, float> point2, char point2Identifier)
  {
    this->segments.push_back(Line(point1, point1Identifier, point2, point2Identifier));

    sort(this->segments.begin(), this->segments.end(), [](const Line &a, const Line &b) -> bool
         { return a.p1.point.second > b.p1.point.second; });
  }

  void print(vector<Line> segments)
  {
    cout << "\nYour given lines are: " << endl;
    for (auto i : segments)
      cout << i.p1.identifier << ": (" << i.p1.point.first << ", " << i.p1.point.second << ")\t" << i.p2.identifier << ": (" << i.p2.point.first << ", " << i.p2.point.second << ") " << endl;
  }

  void print(set<pair<Line, Line>> intersections)
  {
    cout << "\nIntersections: " << endl;
    for (auto i : intersections)
      cout << i.first.p1.identifier << i.first.p2.identifier << " -> " << i.second.p1.identifier << i.second.p2.identifier << ": TRUE" << endl;
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
  myGraph.insertLine({0, 0}, 'A', {1, 1}, 'B');
  myGraph.insertLine({-2, 2}, 'C', {1, 0}, 'D');
  myGraph.insertLine({-6, 2}, 'F', {-4, 4}, 'E');
  myGraph.insertLine({0, 2}, 'H', {-2, 6}, 'G');
  myGraph.insertLine({2, 4}, 'K', {4, 0}, 'L');
  myGraph.insertLine({2, 2}, 'I', {4, 4}, 'J');
  myGraph.print(myGraph.segments);
  myGraph.print(myGraph.intersections);
  myGraph.sweepingLine();
};
