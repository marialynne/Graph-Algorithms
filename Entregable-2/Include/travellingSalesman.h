#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

float travllingSalesmanAlgorithm(vector<vector<float>> graph, int node)
{

    vector<int> vertex;

    for (int i = 0; i < graph.size(); i++)
        if (i != node)
            vertex.push_back(i);

    float min_path = INT_MAX;

    do
    {
        float current_pathweight = 0;
        int currentNode = node;

        for (int i = 0; i < vertex.size(); i++)
        {

            if (graph[currentNode][vertex[i]] == -1 || currentNode == -1)
            {
                current_pathweight = INT_MAX;
                break;
            }
            current_pathweight += graph[currentNode][vertex[i]];
            cout << currentNode << " " << vertex[i] << "  " << current_pathweight << endl;
            currentNode = vertex[i];
        }
        cout << endl;

        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return (min_path != INT_MAX) ? min_path : -1;
}