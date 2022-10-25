#include <iostream>
#include <vector>

void everyNodeDijkstra(vector<vector<vector<int>>> edges);
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);
vector<vector<vector<int>>> convertDataToEdges(vector<vector<int>> data);

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges) // Time: O(n²)
{
    priority_queue<pair<int, int>> pq;
    vector<int> shortestPath(edges.size(), -1);

    pq.push({start, 0});
    shortestPath[start] = 0;

    while (!pq.empty())
    {
        pair<int, int> x = pq.top();
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

vector<vector<vector<int>>> convertDataToEdges(vector<vector<int>> data) // Time: O(n²)
{

    vector<vector<vector<int>>> edges;
    vector<vector<int>> node;
    vector<int> vertexWeight;

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            if (!(data[i][j] == -1 || j == i))
            {
                vertexWeight.push_back(j);          // vertex + 1
                vertexWeight.push_back(data[i][j]); // weight

                node.push_back(vertexWeight);                                 // Save vertex and weight in node
                vertexWeight.erase(vertexWeight.begin(), vertexWeight.end()); // Delete data of vertexWeight
            }
        }

        edges.push_back(node);                // save node in edges
        node.erase(node.begin(), node.end()); // Delete data of node
    }

    print(edges);

    return edges;
}

void everyNodeDijkstra(vector<vector<vector<int>>> edges) // Time: O(n²)
{
    cout << "Dijkstra:" << endl;
    vector<int> minWeight;
    for (int i = 0; i < edges.size(); i++)
    {
        minWeight = dijkstrasAlgorithm(i, edges); // + 1
        for (int j = 0; j < minWeight.size(); j++)
        {
            if (!(i == j)) // Dont show node to the same node
                cout << "Node " << i + 1 << " to Node " << j + 1 << ": " << minWeight[j] << endl;
        }
    }
}
