#include <iostream>
#include <vector>
#include "Include/dijkstra.h"
#include "Include/travellingSalesman.h"
#include "Include/maximumFlow.h"
#include "Include/closestPairOfPoints.h"

using namespace std;

int main()
{
    /* //                                    A  B   C   D   E    F
    vector<vector<float>> firstMatrix = {{0, 16, 45, 32, 5.3, 0}, // A
                                         {0.5, 0, 5, 12, 0, 0},   // B
                                         {3, 18, 0, 7, 0, 0},     // C
                                         {4, 21, 10, 0, 0, 0},    // D
                                         {0, 20.2, 0, 0, 0},      // E
                                         {0, 0, 0, 0, 0, 0}};     // F */

    vector<vector<float>> firstMatrix = {{0, 16, 45, 32, 5.3, -1},  // A
                                         {0.5, 0, 5, 12, -1, -1},   // B
                                         {3, 18, 0, 7, -1, -1},     // C
                                         {4, 21, 10, 0, -1, -1},    // D
                                         {-1, 20.2, -1, -1, 0, -1}, // E
                                         {-1, -1, -1, -1, -1, 0}};  // F

    /* vector<vector<float>> firstMatrix = {{0, 16, 45, 32, 5.3},   // A
                                         {0.5, 0, 5, 12, -1},    // B
                                         {3, 18, 0, 7, -1},      // C
                                         {4, 21, 10, 0, -1},     // D
                                         {-1, 20.2, -1, -1, 0}}; // E */

    vector<vector<float>> secondMatrix = {{0, 48, 12, 18},
                                          {52, 0, 42, 32},
                                          {18, 46, 0, 56},
                                          {24, 36, 52, 0}};

    vector<pair<float, float>> centrals = {{200, 500},
                                           {300, 100},
                                           {450, 150},
                                           {520, 480}};

    everyNodeDijkstra(convertDataToEdges(firstMatrix));
    cout << travllingSalesmanAlgorithm(firstMatrix, 0) << endl;
    return 0;
}