#include <iostream>
#include <cmath>
#include <regex>
#include <vector>

using namespace std;

float abstand(float x1, float y1, float x2, float y2) // Time: O(1)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void findDistances(vector<vector<float>> centrals, vector<vector<float>> colonies) // Time: O(n²)
{
    for (int i = 0; i < colonies.size(); i++)
    {
        float menor = abstand(colonies[i][0], colonies[i][1], centrals[0][0], centrals[0][1]);
        int index = 0;

        for (int j = 0; j < centrals.size(); j++)
        {
            if (to_string(colonies[i][0]) == to_string(centrals[j][0]) && to_string(colonies[i][1]) == to_string(centrals[j][1]))
            {
                cout << "Position of the colony (" << i + 1 << ") Same as that of the plant (" << char(j + 65) << ")! \n";
                menor = 0;
                index = j;
                break;
            }
            else
            {
                float dActual = abstand(colonies[i][0], colonies[i][1], centrals[j][0], centrals[j][1]);

                if (dActual < menor)
                {
                    menor = dActual;
                    index = j;
                }
            }
        }
        if (menor > 0)
            cout << "Colony (" << i + 1 << ") -> Nearest central: (" << char(index + 65) << "), distance: " << menor << " km. \n";
    }
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
    for(int i = 0; i < coordenadas.size(); i ++){
        if(x == coordenadas[i][0] && y == coordenadas[i][1])
        {
            return true;
        }
    }
    return false;
}

void inputsCoordinates(int n) // Time: O(n)
{
    cout << "[Closest Pair Of Points]" << endl;
    cout << "\n";
    cout << "The valid format for coordinates is (X,Y) without spaces.\n";
    cout << "Examples:";
    cout << "\t(2,3)\n";
    cout << "\t\t(-1,-5)\n";
    cout << "\t\t(-3.5,2.7)\n";
    cout << "\t\tetc.\n";

    vector<vector<float>> centrals;
    cout << "\nEnter the coordinates of the centrals below... \n";

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

            if(!validateIfEntered(x, y, centrals))
            {
                centrals.push_back(coor);
            }
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

    vector<vector<float>> colonies;
    int c = 0;
    string col;

    do
    {
        cout << "\nHow many colonies will you enter? ";
        cin >> col;
    } while (!regexNumber(col));

    c = stoi(col);

    for (int i = 0; i < c; i++)
    {
        string colony;
        vector<float> coor;

        cout << "(" << i + 1 << "/" << c << ") Coordinate: ";
        cin >> colony;

        if (regexCoordinate(colony))
        {
            colony.erase(0, 1);
            colony.erase(colony.size() - 1);

            string delimiter = ",";

            float x, y;

            x = stof(colony.substr(0, colony.find(delimiter)));
            coor.push_back(x);
            colony.erase(0, colony.find(delimiter) + delimiter.length());
            coor.push_back(stof(colony));
            y = stof(colony);

            if(!validateIfEntered(x, y, colonies))
            {
                colonies.push_back(coor);
            }
            else
            {
                i--;
                cout << "Invalid entry. Coordinates have already been registered for another colony.\n";
            }
        }
        else
        {
            i--;
            cout << "\nInvalid entry. Retry...\n";
        }
    }

    cout << "\n\n";
    findDistances(centrals, colonies);
}