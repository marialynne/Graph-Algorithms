#include <iostream>
#include <vector>
#include "Include/readingData.h"
#include "Include/dijkstra.h"
#include "Include/travellingSalesman.h"
#include "Include/maximumFlow.h"
#include "Include/closestPairOfPoints.h"
#include "Include/matrixValidation.h"

using namespace std;

int main()
{
    vector<vector<string>> stringMatrix1 = getMatrix1();
    vector<vector<string>> stringMatrix2 = getMatrix2();
    char cn[100];
    int n;

    do
    {
        cout << "Entern n: ";
        cin.getline(cn, 100);

    } while (!regexNumber(cn));

    n = stoi(cn);

    cout << "\n\n--------------------VALIDATION--------------------\n\n";

    vector<vector<float>> resultingMatrix1 = generalValidations(stringMatrix1, 1);
    vector<vector<float>> resultingMatrix2 = generalValidations(stringMatrix2, 2);

    if (resultingMatrix1.size() != n || resultingMatrix2.size() != n)
    {
        cout << "\n\t << Invalid data! >>";
        exit(0);
    }

    if (resultingMatrix1.empty() || resultingMatrix2.empty())
    {
        cout << "\n\t<< Invalid data! >>\n";
        exit(0);
    }
    else
    {
        cout << "\n\t<< Checking correspondence... >>\n";

        if (matrixCorrespondence(resultingMatrix1, resultingMatrix2))
            cout << "\n\t<< Valid data! >>\n";
        else
        {
            cout << "\n\t<< Invalid data! >>\n";
            exit(0);
        }
    }

    cout << "\n\n---------------------Matrix 1---------------------\n\n";

    for (auto row : resultingMatrix1)
    {
        for (auto el : row)
            cout << el << "\t";
        cout << "\n";
    }

    cout << "\n---------------------Matrix 2---------------------\n\n";

    for (auto row : resultingMatrix2)
    {
        for (auto el : row)
            cout << el << "\t";
        cout << "\n";
    }

    cout << "\n\n----------------------PART 1----------------------\n\n";
    everyNodeDijkstra(convertDataToEdges(resultingMatrix1));
    cout << "\n\n----------------------PART 2----------------------\n\n";
    travellingSalesmanAlgorithm(resultingMatrix1, 0);
    cout << "\n\n----------------------PART 3----------------------\n\n";
    maxFlow(resultingMatrix2, resultingMatrix2.size());
    cout << "\n\n----------------------PART 4----------------------\n\n";
    inputsCoordinates(resultingMatrix1.size());
    return 0;
}