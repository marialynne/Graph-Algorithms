#include <iostream>
#include <vector>
#include "dijkstra.h"
#include "maximumFlow.h"
#include "travelingSalesman.h"

using namespace std;

int main()
{
    vector<vector<int>> firstMatrix = {{0, 16, 45, 32},
                                       {16, 0, 18, 21},
                                       {45, 18, 0, 7},
                                       {32, 21, 7, 0}};

    vector<vector<int>> secondMatrix = {{0, 48, 12, 18},
                                        {52, 0, 42, 32},
                                        {18, 46, 0, 56},
                                        {24, 36, 52, 0}};

    vector<pair<int, int>> centrals = {{200, 500},
                                       {300, 100},
                                       {450, 150},
                                       {520, 480}};

    everyNodeDijkstra(convertDataToEdges(firstMatrix));
    return 0;
}