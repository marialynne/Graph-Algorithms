#include <iostream>
#include <vector>
#include "Include/dijkstra.h"
#include "Include/travellingSalesman.h"
#include "Include/maximumFlow.h"
#include "Include/closestPairOfPoints.h"
#include "Include/matrixValidation.h"

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

//    vector<vector<float>> secondMatrix = {{0, 48, 12, 18},
//                                        {52, 0, 42, 32},
//                                        {18, 46, 0, 56},
//                                        {24, 36, 52, 0}};

    vector<vector<float>> secondMatrix = {{0, 10, 8, 5, 0, 0, 0},
                                         {0, 0, 7, 0, 6, 0, 0},
                                         {0, 0, 0, 4, 0, 3, 0},
                                         {0, 0, 0, 0, 0, 10, 0},
                                         {0, 0, 0, 0, 0, 8, 2},
                                         {0, 0, 0, 0, 0, 0, 9},
                                         {0, 0, 0, 0, 0, 0, 0}};

    vector<vector<string>> stringMatrix = {{"0", "-1", "8", "5", "-1", "-1", "-1"},
                                            {"-1", "0", "-1", "-1", "6", "-1", "-1"},
                                            {"2", "-1", "0", "4", "-1", "3", "-1"},
                                            {"-1", "-1", "-1", "0", "-1", "1", "-1"},
                                            {"-1", "-1", "-1", "-1", "0", "8", "2"},
                                            {"-1", "-1", "-1", "-1", "-1", "0", "9"},
                                            {"-1", "-1", "-1", "-1", "-1", "-1", "0"}};

    vector<vector<string>> stringMatrix2 = {{"0", "0", "-8", "5", "0", "0", "0"},
                                            {"0", "0", "0", "0", "6", "0", "0"},
                                            {"0", "0", "0", "4", "0", "3", "0"},
                                            {"0", "0", "0", "0", "0", "1", "0"},
                                            {"0", "0", "0", "0", "0", "8", "2"},
                                            {"0", "0", "0", "0", "0", "0", "9"},
                                            {"0", "0", "0", "0", "0", "0", "0"}};

//    vector<vector<float>> secondMatrix = {{0, 10, 0, 10, 0, 0},
//                                         {0, 0, 4, 2, 8, 0, 0},
//                                         {0, 0, 0, 4, 0, 3, 10},
//                                         {0, 0, 0, 9, 0, 10, 0},
//                                         {0, 0, 0, 0, 0, 8, 10},
//                                         {0, 0, 0, 0, 0, 0, 0}};

    vector<pair<float, float>> centrals = {{200, 500},
                                           {300, 100},
                                           {450, 150},
                                           {520, 480}};


  vector<vector<float>> resultingMatrix = generalValidations(stringMatrix, 1);
  vector<vector<float>> resultingMatrix2 = generalValidations(stringMatrix2, 2);
  if (resultingMatrix.empty() || resultingMatrix2.empty()) {
    cout << "DATOS NO VALIDOS \n";
  } else {
    cout << "CHECANDO CORRESPONDENCIA \n";
    bool corresponding = matrixCorrespondence(resultingMatrix, resultingMatrix2);
    if (corresponding) {
      cout << "MATRICES SON CORRECTAS \n";
    } else {
      cout << "ESTO NO CONCUERDA\n";
    }
  }

  cout << "\n\n Matriz 1 \n";

  for (auto row : resultingMatrix) {
    for (auto el : row) {
      cout << el << "   ";
    }
    cout << "\n ";
  }

  cout << "\n Matriz 2 \n";

  for (auto row : resultingMatrix2) {
    for (auto el : row) {
      cout << el << "   ";
    }
    cout << "\n ";
  }


    everyNodeDijkstra(convertDataToEdges(firstMatrix));
    cout << travllingSalesmanAlgorithm(firstMatrix, 0) << endl;
    maxFlow(secondMatrix, secondMatrix.size());
    return 0;
}