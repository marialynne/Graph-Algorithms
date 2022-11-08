#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include <tuple>

using namespace std;

/* n -> validar numero entero positivo mayor a 2
coordenada -> formato (9.99,9.99) -> Es lo que hizo augusto
No coordenadas repeditas -> Lo que hizo augusto */

bool regexNumber(string numb) // Time: O(1)
{
    const regex expReg("^-?[0-9]+$");
    return regex_match(numb, expReg);
}

bool regexCoordinate(string coor) // Time: O(1)
{
    const regex expReg("^\\(([+-]?([0-9]*[.])?[0-9]+)[,]([+-]?([0-9]*[.])?[0-9]+)\\)+$");
    return regex_match(coor, expReg);
}

bool validateIfEntered(float x, float y, vector<tuple<float, float>> coordenadas) // Time: O(n)
{
    for(int i = 0; i < coordenadas.size(); i ++){
        if(x == get<0>(coordenadas[i]) && y == get<1>(coordenadas[i]))
        {
            return true;
        }
    }
    return false;
}

int main()
{
  vector<tuple<float, float>> points;
  string n;
  cout << "Input n: \n";
  cin >> n;

  if (!regexNumber(n)) {
    cout << "n has to be a number bigger than 2 \n";
    exit(0);
  }
  
  int numN = stoi(n);

  if (numN <= 2) {
    cout << "n has to be a number bigger than 2 \n";
    exit(0);
  }

  for (int i = 0; i < numN; i++)
  {
      string coordinate;
      tuple<float, float> coor;
      cout << "(" << i + 1 << "/" << n << ") Coordinate: ";

      cin >> coordinate;

      if (regexCoordinate(coordinate)) {
        coordinate.erase(0, 1);
        coordinate.erase(coordinate.size() - 1);

        string delimiter = ",";

        float x, y;

        x = stof(coordinate.substr(0, coordinate.find(delimiter)));
        coordinate.erase(0, coordinate.find(delimiter) + delimiter.length());
        y = stof(coordinate);
        get<0>(coor) = x;
        get<1>(coor) = y;

        if(!validateIfEntered(x, y, points))
        {
            points.push_back(coor);
        }
        else
        {
            i--;
            cout << "Invalid entry. Coordinates have already been registered. \n";
        }
      }

  }

  // PRINT POINTS TO SEE IF THIS WORKS
  for (auto tupla : points) {
    cout << "(" << get<0>(tupla) << "," << get<0>(tupla) << ") \n";
  }

    /* vector<tuple<float, float>> points = {{0, 3},
                                          {1, 1},
                                          {2, 2},
                                          {4, 4},
                                          {0, 0},
                                          {1, 2},
                                          {3, 1},
                                          {3, 3},
                                          {-1, 0},
                                          {-3, 0},
                                          {1, 4},
                                          {-4, 1}}; */
    return 0;
}