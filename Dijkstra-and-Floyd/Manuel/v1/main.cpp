//#include "dijkstra.h"
//#include "floyd.h"
#include <bits/stdc++.h>
using namespace std;
/*
Pasos a seguir:
    - Crear nodos con sus respectivos vertex y weight
        - Funciona que recolecta datos y los agrega con nodos anidados con su respectivo peso
    - Hacer un algoritmo que recorra cada uno de los nodos
    - Buscar la menor distancia entre cada nodo

*/
vector<vector<vector<int>>> getData();
vector<vector<vector<int>>> convertDataToEdges(vector<vector<int>> data);
void print(vector<vector<int>> data);
void print(vector<vector<vector<int>>> edges);
void everyNodeDijkstra(vector<vector<vector<int>>> edges);
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);
bool checkMatrix(vector<vector<int>> data);

int main()
{
    vector<vector<vector<int>>> edges = getData();
    everyNodeDijkstra(edges);
    return 0;
}

void everyNodeDijkstra(vector<vector<vector<int>>> edges)
{
    cout << "Dijkstra:" << endl;
    vector<int> minWeight;
    for (int i = 0; i < edges.size(); i++)
    {
        minWeight = dijkstrasAlgorithm(i, edges);
        for (int j = 0; j < minWeight.size(); j++)
        {
            if (!(i == j)) // Dont show node to the same node
                cout << "Node " << i + 1 << " to Node " << j + 1 << ": " << minWeight[j] << endl;
        }
    }
}

vector<vector<vector<int>>> getData() // Time: O(n²)
{
    int n, input;
    vector<vector<int>> data; // (n, vector<int>(n, 0))

    cout << "Please, enter n: ";
    cin >> n;

    while (n < 2) // Here should go n to verification (positive integer)a
    {
        cout << "[ERROR]: n must be greater than 1. \nPlease, enter n: ";
        cin >> n;
    }

    cout << "Now, enter your data: " << endl;

    do
    {
        for (int i = 0; i < n; i++)
        {
            vector<int> row;
            for (int j = 0; j < n; j++)
            {
                cin >> input;
                row.push_back(input);
                // here should go the input to verification (integer, input >= -1 )
            }
            data.push_back(row);
            // Here there should be a '0' check between the same node
        }
    } while (checkMatrix(data));

    print(data);

    return convertDataToEdges(data);
}

bool checkMatrix(vector<vector<int>> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); i++)
        {
            regex regex("[1-9]|[-][1]");

            if (i == j && !(data[i][j] == 0))
            {

                cout << "[ERROR]: Invalid data, there must be 0 between i == j" << endl;
                cout << "Please, enter your data again: " << endl;
                return true;
            }
            else if (data[i][j] != -1 || data[i][j])
            {
                cout << "[ERROR]: Invalid data, numbers must be -1 or greater than 0" << endl;
                cout << "Please, enter your data again: " << endl;
                return true;
            }
        }
    }
    return false;
}

vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges)
{
    priority_queue<pair<int, int>> pq;
    vector<int> v(edges.size(), -1);

    pq.push({start, 0});
    v[start] = 0;

    while (!pq.empty())
    {
        auto x = pq.top();
        pq.pop();

        for (auto s : edges[x.first])
        {
            if (v[x.first] + s[1] < v[s[0]] || v[s[0]] == -1)
            {
                v[s[0]] = v[x.first] + s[1];
                pq.push({s[0], v[s[0]]});
            }
        }
    }
    return v;
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
                vertexWeight.push_back(j);          // vertex
                vertexWeight.push_back(data[i][j]); // weight

                node.push_back(vertexWeight);                                 // Save vertex and weight in node
                vertexWeight.erase(vertexWeight.begin(), vertexWeight.end()); // Delete data of vertexWeight
            }
        }

        edges.push_back(node);                // save node in edges
        node.erase(node.begin(), node.end()); // Delete data of node
    }

    // print(edges);

    return edges;
}

void print(vector<vector<int>> data) // Time: O(n²)
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

void print(vector<vector<vector<int>>> edges) // Time: O(n²)
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
