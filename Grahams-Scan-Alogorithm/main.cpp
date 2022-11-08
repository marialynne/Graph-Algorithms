#include <iostream>
#include <stack>
#include <stdlib.h>
#include <tuple>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>

using namespace std;
tuple<float, float> p0;

tuple<float, float> nextToTop(stack<tuple<float, float>> &S) // Time: O(1)
{
    tuple<float, float> p = S.top();
    S.pop();
    tuple<float, float> res = S.top();
    S.push(p);
    return res;
}

float distSq(tuple<float, float> p1, tuple<float, float> p2) // Time: O(1)
{
    return (get<0>(p1) - get<0>(p2)) * (get<0>(p1) - get<0>(p2)) +
           (get<1>(p1) - get<1>(p2)) * (get<1>(p1) - get<1>(p2));
}

int orientation(tuple<float, float> p, tuple<float, float> q, tuple<float, float> r) // Time: O(1)
{
    int val = (get<1>(q) - get<1>(p)) * (get<0>(r) - get<0>(q)) -
              (get<0>(q) - get<0>(p)) * (get<1>(r) - get<1>(q));

    if (val == 0)
        return 0;             // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

int compare(const void *vp1, const void *vp2) // Time: O(1)
{
    tuple<float, float> *p1 = (tuple<float, float> *)vp1;
    tuple<float, float> *p2 = (tuple<float, float> *)vp2;

    // Find orientation
    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1;

    return (o == 2) ? -1 : 1;
}

void print(vector<tuple<float, float>> points) // Time: O(n)
{
    for (auto i : points)
        cout << "(" << get<0>(i) << ", " << get<1>(i) << ")" << endl;
}

void convexHullAlgorithm(vector<tuple<float, float>> points) // Time: O(n^2)
{
    float yMin = get<1>(points[0]), minIndex = 0;

    for (int i = 1; i < points.size(); i++)
    {
        float y = get<1>(points[i]);
        if ((y < yMin) || yMin == y && get<0>(points[i]) < get<0>(points[minIndex]))
            yMin = get<1>(points[i]), minIndex = i;
    }

    swap(points[0], points[minIndex]);

    p0 = points[0];
    qsort(&points[1], points.size() - 1, sizeof(tuple<float, float>), compare);

    int m = 1;
    for (int i = 1; i < points.size(); i++)
    {
        while (i < points.size() - 1 && orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        points[m] = points[i];
        m++;
    }

    if (m < 3)
    {
        cout << "Its a line :(" << endl;
        return;
    }

    stack<tuple<float, float>> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++)
    {
        while (S.size() > 1 && orientation(nextToTop(S), S.top(), points[i]) != 2)
            S.pop();
        S.push(points[i]);
    }

    vector<tuple<float, float>> ans;

    while (!S.empty())
    {
        ans.insert(ans.begin(), S.top());
        S.pop();
    }

    print(ans);
}

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
    for (int i = 0; i < coordenadas.size(); i++)
    {
        if (x == get<0>(coordenadas[i]) && y == get<1>(coordenadas[i]))
            return true;
    }
    return false;
}

int main()
{
    vector<tuple<float, float>> points;
    string n;
    cout << "Input n: ";
    cin >> n;

    if (!regexNumber(n))
    {
        cout << "n has to be a number bigger than 2 \n";
        exit(0);
    }

    int numN = stoi(n);

    if (numN <= 2)
    {
        cout << "n has to be a number bigger than 2 \n";
        exit(0);
    }

    for (int i = 0; i < numN; i++)
    {
        string coordinate;
        tuple<float, float> coor;
        cout << "(" << i + 1 << "/" << n << ") Coordinate: ";

        cin >> coordinate;

        if (regexCoordinate(coordinate))
        {
            coordinate.erase(0, 1);
            coordinate.erase(coordinate.size() - 1);

            string delimiter = ",";

            float x, y;

            x = stof(coordinate.substr(0, coordinate.find(delimiter)));
            coordinate.erase(0, coordinate.find(delimiter) + delimiter.length());
            y = stof(coordinate);
            get<0>(coor) = x;
            get<1>(coor) = y;

            if (!validateIfEntered(x, y, points))
            {
                points.push_back(coor);
            }
            else
            {
                i--;
                cout << "Invalid entry. Coordinates have already been registered. \n";
            }
        }
        else
        {
            i--;
            cout << "\nInvalid entry. Retry...\n";
        }
    }

    /*  points = {{0, 3},
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

    convexHullAlgorithm(points);
    return 0;
}