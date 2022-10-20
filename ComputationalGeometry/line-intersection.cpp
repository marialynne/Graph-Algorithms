//
// Created by Carla Onate on 19/10/22.
//
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

class Line {
  public:
    pair<int, int> p1;
    pair<int, int> p2;
    Line (pair<int, int> point1, pair<int, int> point2) {
      this->p1 = point1;
      this->p2 = point2;
    }
};

vector<Line> getData () {
  // YA NO ENTENDI COMO RECIBIR DATOS - DLV
  vector<Line> lines;
  int numberLines;

  cout << "Ingresa un numero multiplo de 4" << "\n";
  cin >> numberLines;

  return lines;
};

bool checkSegment (pair<int, int> point1, pair<int, int> point2, pair<int, int> point3) {
  if ( point3.first <= max (point1.first, point2.first) && point3.first >= min (point1.first, point2.first) &&
       point3.second <= max (point1.second, point2.second) && point3.second >= min (point1.second, point2.second) ) {
    return true;
  }
  return false;
}

int orientation (pair<int, int> point1, pair<int, int> point2, pair<int, int> point3) {
  int orientation = ((point3.first - point1.first) * (point2.second - point1.second)) - ((point2.first - point1.first) * (point3.second - point1.second));

  if (orientation == 0) return 0;
  if (orientation > 0) return 1;
    return 2;
}

bool intersect (Line line1, Line line2) {
  int line1toLine2_p1_Orientation = orientation(line1.p1, line1.p2, line2.p1);
  int line1toLine2_p2_Orientation = orientation(line1.p1, line1.p2, line2.p2);
  int line2toLine1_p1_Orientation = orientation(line2.p1, line2.p2, line1.p1);
  int line2toLine1_p2_Orientation = orientation(line2.p1, line2.p2, line1.p2);

  if (line1toLine2_p1_Orientation != line1toLine2_p2_Orientation && line2toLine1_p1_Orientation != line2toLine1_p2_Orientation)
    return true;

  if (line1toLine2_p1_Orientation == 0 && checkSegment (line1.p1, line1.p2, line2.p1)) return true;
  if (line1toLine2_p2_Orientation == 0 && checkSegment (line1.p1, line1.p2, line2.p2)) return true;
  if (line2toLine1_p1_Orientation == 0 && checkSegment (line2.p1, line2.p2, line1.p1)) return true;
  if (line2toLine1_p2_Orientation == 0 && checkSegment (line2.p1, line2.p2, line1.p2)) return true;

  return false;
};

int main () {
 //vector<Line> lines = getData();
 Line line1 = Line({0, 0}, {1, 1});
 Line line2 = Line({-2, 2}, {1, 0});

 bool intersectan = intersect(line1, line2);
 cout << "\n" << intersectan << "\n";
};
