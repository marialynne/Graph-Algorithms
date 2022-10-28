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
    /* stringMatrix1 = {{"0", "16", "45", "32"},
                     {"16", "0", "18", "21"},
                     {"45", "18", "0", "7"},
                     {"32", "21", "7", "0"}};
    stringMatrix2 = {{"0", "1", "45", "32"},
                     {"16", "0", "18", "21"},
                     {"45", "8", "0", "1"},
                     {"32", "21", "7", "0"}}; */

    cout << "\n\n--------------------VALIDATION--------------------\n\n";

    vector<vector<float>> resultingMatrix1 = generalValidations(stringMatrix1, 1);
    vector<vector<float>> resultingMatrix2 = generalValidations(stringMatrix2, 2);

    if (resultingMatrix1.empty() || resultingMatrix2.empty())
        cout << "\n\t<< Invalid data! >>\n";
    else
    {
        cout << "\n\t<< Checking correspondence... >>\n";

        if (matrixCorrespondence(resultingMatrix1, resultingMatrix2))
            cout << "\n\t<< Valid data! >>\n";
        else
            cout << "\n\t<< Invalid data! >>\n";
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