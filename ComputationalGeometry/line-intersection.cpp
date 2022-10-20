//
// Created by Carla Onate on 19/10/22.
//
#include <vector>
#include <iostream>
#include <utility>

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

int orientation (pair<int, int> point1, pair<int, int> point2, pair<int, int> point3) {
  int orientation = (point3.first - point1.first) * (point2.second - point1.second) - (point2.first - point1.first) * (point2.second - point1.second);

  cout << "\n\t orientation : " << orientation << "\n";

  if (orientation == 0) return 0;
  if (orientation > 0) return 1;
    return 2;
}


int main () {
 //vector<Line> lines = getData();
 Line line1 = Line({0, 0}, {2, 1});
 Line line2 = Line({-1, -1}, {1, -1});

 int line1toLine2_p1_Orientation = orientation(line1.p1, line1.p2, line2.p1);
 int line1toLine2_p2_Orientation = orientation(line1.p1, line1.p2, line2.p2);

 cout << " line 1 to line 2 p1 " << line1toLine2_p1_Orientation <<"\n";
 cout << " line 1 to line 2 p2 " << line1toLine2_p2_Orientation <<"\n";
};
