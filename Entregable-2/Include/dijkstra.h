#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void everyNodeDijkstra(vector<vector<vector<float>>> edges);
vector<float> dijkstrasAlgorithm(float start, vector<vector<vector<float>>> edges);
vector<vector<vector<float>>> convertDataToEdges(vector<vector<float>> data);
void print(vector<vector<float>> data);
void print(vector<vector<vector<float>>> edges);

vector<float> dijkstrasAlgorithm(float start, vector<vector<vector<float>>> edges) // Time: O(n²)
{
    priority_queue<pair<float, float>> pq;
    vector<float> shortestPath(edges.size(), -1);

    pq.push({start, 0});
    shortestPath[start] = 0;

    while (!pq.empty())
    {
        pair<float, float> x = pq.top();
        pq.pop();

        for (auto s : edges[x.first])
        {
            if (shortestPath[x.first] + s[1] < shortestPath[s[0]] || shortestPath[s[0]] == -1)
            {
                shortestPath[s[0]] = shortestPath[x.first] + s[1];
                pq.push({s[0], shortestPath[s[0]]});
            }
        }
    }
    return shortestPath;
}

vector<vector<vector<float>>> convertDataToEdges(vector<vector<float>> data) // Time: O(n²)
{
    vector<vector<vector<float>>> edges;
    vector<vector<float>> node;
    vector<float> vertexWeight;
    vector<float> empty;

    for (int i = 0; i < data.size(); i++)
    {
        int sumEmpty = 0;
        for (int j = 0; j < data[i].size(); j++)
        {
            if (!(data[i][j] == -1 || j == i))
            {
                vertexWeight.push_back(j);          // vertex
                vertexWeight.push_back(data[i][j]); // weight

                node.push_back(vertexWeight);                                 // Save vertex and weight in node
                vertexWeight.erase(vertexWeight.begin(), vertexWeight.end()); // Delete data of vertexWeight
            }

            if (data[i][j] == -1)
            {
                sumEmpty++;
                empty.push_back(data[i][j]);

                if (sumEmpty == data.size()) // if is the same currentRow
                {
                    if (empty.size() == data.size())
                    {
                        edges.push_back({});                     // Save empty edge
                        empty.erase(empty.begin(), empty.end()); // Remove completed vector
                    }
                }
                else // Remove not completed empty vector
                    empty.erase(empty.begin(), empty.end());
            }
        }

        edges.push_back(node);                // save node in edges
        node.erase(node.begin(), node.end()); // Delete data of node
    }

    print(edges);

    return edges;
}

void everyNodeDijkstra(vector<vector<vector<float>>> edges) // Time: O(n²)
{
    cout << "Dijkstra:" << endl;
    vector<float> minWeight;
    for (int i = 0; i < edges.size(); i++)
    {
        minWeight = dijkstrasAlgorithm(i, edges); // + 1
        for (int j = 0; j < minWeight.size(); j++)
        {
            if (!(i == j)) // Dont show node to the same node
                cout << "Node " << char(65 + i) << " to Node " << char(65 + j) << ": " << minWeight[j] << endl;
        }
    }
}

void print(vector<vector<float>> data) // Time: O(n²)
{
    for (auto i : data)
    {
        cout << "\t";
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << endl;
}

void print(vector<vector<vector<float>>> edges) // Time: O(n²)
{
    cout << "\nEdges (vertex, weight):" << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        cout << "Node " << char(65 + i) << ": [ ";
        for (int j = 0; j < edges[i].size(); j++)
        {
            cout << "[";

            cout << char(65 + edges[i][j][0]) << ", " << edges[i][j][1];

            cout << "] ";
        }
        cout << "]";
        cout << endl;
    }
    cout << endl;
}
