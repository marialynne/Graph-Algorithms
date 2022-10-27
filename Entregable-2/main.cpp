#include <iostream>
#include <vector>
//#include "djikstra.h"
#include "./Include/maximumFlow.h"
//#include "travelingSalesman.h"

using namespace std;

int main()
{
    vector<vector<int>> firstMatrix = {{0, 16, 45, 32},
                                       {16, 0, 18, 21},
                                       {45, 18, 0, 7},
                                       {32, 21, 7, 0}};

//    vector<vector<float>> secondMatrix = {{0, 48, 12, 18},
//                                        {52, 0, 42, 32},
//                                        {18, 46, 0, 56},
//                                        {24, 36, 52, 0}};

//    vector<vector<float>> secondMatrix = {{0, 10, 8, 5, 0, 0, 0},
//                                         {0, 0, 7, 0, 6, 0, 0},
//                                         {0, 0, 0, 4, 0, 3, 0},
//                                         {0, 0, 0, 0, 0, 10, 0},
//                                         {0, 0, 0, 0, 0, 8, 2},
//                                         {0, 0, 0, 0, 0, 0, 9},
//                                         {0, 0, 0, 0, 0, 0, 0}};
//
    vector<vector<float>> secondMatrix = {{0, 10, 0, 10, 0, 0},
                                         {0, 0, 4, 2, 8, 0, 0},
                                         {0, 0, 0, 4, 0, 3, 10},
                                         {0, 0, 0, 9, 0, 10, 0},
                                         {0, 0, 0, 0, 0, 8, 10},
                                         {0, 0, 0, 0, 0, 0, 0}};

    vector<pair<int, int>> centrals = {{200, 500},
                                       {300, 100},
                                       {450, 150},
                                       {520, 480}};

    // everyNodeDijkstra(convertDataToEdges(firstMatrix));
    maxFlow(secondMatrix, secondMatrix.size());
    return 0;
}