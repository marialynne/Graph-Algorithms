#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void travellingSalesmanAlgorithm(vector<vector<float>> graph, int node) // Time: O(n²)
{
    vector<int> vertex;
    vector<int> tempSteps, steps;

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

            currentNode = vertex[i];
            tempSteps.push_back(currentNode);
        }

        for (auto row : edges[currentNode])
        {
            if (row[0] == node && current_pathweight < min_path)
            {
                steps = tempSteps;
                current_pathweight += row[1];
                min_path = min(min_path, current_pathweight);
            }
            tempSteps.clear();
        }

    } while (next_permutation(vertex.begin(), vertex.end()));

    if (min_path != INT_MAX)
    {
        cout << "\nRoute: ";
        cout << char(65 + node) << " -> ";
        for (auto i : steps)
            cout << char(65 + i) << " -> ";
        cout << char(65 + node) << endl;
        cout << "[Travelling Salesman]: " << min_path << "\n\n";
    }
    else
        cout << "\n[Travlling Salesman]: Unable to traverse all nodes at least once\n\n";
}