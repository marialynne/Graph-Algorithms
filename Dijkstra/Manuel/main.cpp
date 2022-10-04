#include <vector>
#include <set>
#include <iostream>
using namespace std;
vector<vector<vector<int>>> getData();
vector<vector<vector<int>>> convertDataToEdges(vector<vector<int>> data);
void print(vector<vector<int>> data);
void print(vector<vector<vector<int>>> edges);
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);

int main()
{
    vector<vector<vector<int>>> edges = getData();
    vector<int> minWeight;

    for (int i = 0; i < edges.size(); i++)
    {
        minWeight = dijkstrasAlgorithm(i + 1, edges);
        for (int j = 0; j < minWeight.size(); j++)
        {
            if (!(i == j)) // Dont show node to the same node
                cout << "Node " << i + 1 << " to Node " << j + 1 << ": " << minWeight[j] << endl;
        }
    }

    return 0;
}

vector<vector<vector<int>>> getData()
{
    int n, input;
    vector<vector<int>> data; // (n, vector<int>(n, 0))

    cout << "Please, enter n: ";
    cin >> n; // Here should go n to verification (positive integer)

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < n; j++)
        {
            cin >> input;
            row.push_back(input); // here should go the input to verification (integer, input >= -1 )
        }
        data.push_back(row);
        // verification '0' between the same node
    }

    print(data);

    return convertDataToEdges(data);
}

vector<vector<vector<int>>> convertDataToEdges(vector<vector<int>> data)
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
                // cout << data[i][j] << " ";
                vertexWeight.push_back(j + 1);      // vertex
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

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges)
{
    int n = edges.size();
    vector<int> dist_ans(n, -1);
    set<pair<int, int>> dist;
    dist_ans[start] = 0;

    while (!dist.empty())
    {
        auto node = dist.begin()->second;
        dist.erase(dist.begin());

        for (int i = 0; i < edges[node].size(); i++)
        {
            int dest = edges[node][i][0];
            int weight = edges[node][i][1];
            int new_weight = dist_ans[node] + weight;

            if (dist_ans[dest] == -1 || (new_weight < dist_ans[dest]))
            {
                dist_ans[dest] = new_weight;
                dist.emplace(new_weight, dest);
            }
        }
    }

    return dist_ans;
}

void print(vector<vector<int>> data)
{
    cout << "\nYour input data: " << endl;
    for (auto i : data)
    {
        cout << "\t";
        for (auto j : i)
            cout << j << " ";
        cout << "\n";
    }
    cout << endl;
}

void print(vector<vector<vector<int>>> edges)
{
    cout << "\nEdges (vertex, weight):" << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        cout << "Node " << i + 1 << ": [";
        for (auto j : edges[i])
        {
            cout << "[";
            for (auto k : j)
            {
                cout << k << ",";
            }
            cout << "],";
        }
        cout << "]";
        cout << endl;
    }
    cout << endl;
}
