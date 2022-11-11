#include <iostream>
#include <cmath>
#include <regex>
#include <vector>

using namespace std;
float abstand(float x1, float y1, float x2, float y2);
void findDistances(vector<vector<float>> coordinates);
bool regexNumber(string numb);
bool regexFloat(string numb);
bool regexCoordinate(string coor);
bool validateIfEntered(float x, float y, vector<vector<float>> coordinates);
void inputsCoordinates(int n);

int main()
{
    string n;
    cout << "Only an integer, otherwise N will be asked until it is correct.\n";
    do
    {
        cout << "Enter N: ";
        cin >> n;
    } while (!regexNumber(n));

    if (stoi(n) > 1)
        inputsCoordinates(stoi(n));
    else
        cout << "N is 1, so there is nothing to evaluate. The shortest distance by default is 0.\n";

    return 0;
}

void inputsCoordinates(int n)
{
    cout << "[Closest Pair Of Points]" << endl;
    cout << "\n";
    cout << "The valid format for coordinates is (X,Y) without spaces.\n";
    cout << "Examples:";
    cout << "\t(2,3)\n";
    cout << "\t\t(-1,-5)\n";
    cout << "\t\t(-3.5,2.7)\n";
    cout << "\t\tetc.\n";

    vector<vector<float>> coordinates;
    cout << "\nEnter the coordinates below... \n";

    for (int i = 0; i < n; i++)
    {
        string coordinate;
        vector<float> coor;
        cout << "(" << i + 1 << "/" << n << ") Coordinate: ";

        cin >> coordinate;

        if (regexCoordinate(coordinate))
        {
            coordinate.erase(0, 1);
            coordinate.erase(coordinate.size() - 1);

            string delimiter = ",";

            float x, y;

            x = stof(coordinate.substr(0, coordinate.find(delimiter)));
            coor.push_back(x);
            coordinate.erase(0, coordinate.find(delimiter) + delimiter.length());
            coor.push_back(stof(coordinate));
            y = stof(coordinate);

            if (!validateIfEntered(x, y, coordinates))
                coordinates.push_back(coor);
            else
            {
                i--;
                cout << "Invalid entry. Coordinates have already been registered for another central.\n";
            }
        }
        else
        {
            i--;
            cout << "\nInvalid entry. Retry...\n";
        }
    }

    cout << "\n\n";
    findDistances(coordinates);
}

float abstand(float x1, float y1, float x2, float y2) // Time: O(1)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void findDistances(vector<vector<float>> coordinates) // Time: O(n²)
{
    float shortest = 0;

    for (int i = 0; i < coordinates.size(); i++)
    {
        shortest = abstand(coordinates[i][0], coordinates[i][1], coordinates[0][0], coordinates[0][1]);

        for (int j = 0; j < coordinates.size(); j++)
        {
            if (i != j && abstand(coordinates[i][0], coordinates[i][1], coordinates[j][0], coordinates[j][1]) <= shortest)
                shortest = abstand(coordinates[i][0], coordinates[i][1], coordinates[j][0], coordinates[j][1]);
        }
    }
    cout << "The shortest distance is: " << shortest;
}

bool regexNumber(string numb) // Time: O(1)
{
    const regex expReg("^[0-9]+$");
    return regex_match(numb, expReg);
}

bool regexFloat(string numb) // Time: O(1)
{
    const regex expReg("^[+-]?([0-9]*[.])?[0-9]+$");
    return regex_match(numb, expReg);
}

bool regexCoordinate(string coor) // Time: O(1)
{
    const regex expReg("^\\(([+-]?([0-9]*[.])?[0-9]+)[,]([+-]?([0-9]*[.])?[0-9]+)\\)+$");
    return regex_match(coor, expReg);
}

bool validateIfEntered(float x, float y, vector<vector<float>> coordenadas) // Time: O(n)
{
    for (int i = 0; i < coordenadas.size(); i++)
        return (x == coordenadas[i][0] && y == coordenadas[i][1]);

    return false;
}
