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
vector<vector<int>> getData();
vector<vector<vector<int>>> convertDataToEdges(vector<vector<int>> data);
void print(vector<vector<int>> data);
void print(vector<vector<vector<int>>> edges);
void everyNodeDijkstra(vector<vector<vector<int>>> edges);
vector<int> dijkstrasAlgorithm(int start, vector<vector<vector<int>>> edges);
bool checkMatrix(vector<vector<int>> data);
void floyd(vector<vector<int>> data);

int main()
{
    vector<vector<int>> data = getData();
    vector<vector<vector<int>>> edges = convertDataToEdges(data);

    everyNodeDijkstra(edges);
    floyd(data);

    return 0;
}

void floyd(vector<vector<int>> data) // Time: O(n³)
{
    cout << "\nFloyd Warshall" << endl;

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size(); j++)
        {
            if (data[i][j] == -1)
                data[i][j] = 99999;
        }
    }

    for (int k = 0; k < data.size(); k++)
    {
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = 0; j < data.size(); j++)
            {
                data[i][j] = min(data[i][j], data[i][k] + data[k][j]);
            }
        }
    }

    print(data);
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

vector<vector<int>> getData() // Time: O(n²)
{
    char nchar[100];
    int n, input;
    vector<vector<int>> data; // (n, vector<int>(n, 0))

    regex regexN("([2-9])+"); // 2, ...

    cout << "Please, enter n: ";
    cin.getline(nchar, 100);

    while (!regex_match(nchar, regexN)) // Here should go n to verification (positive integer)a
    {
        cout << "[ERROR]: n must be a number greater than 1. \nPlease, enter n: ";
        cin.getline(nchar, 100);
    }

    n = stoi(nchar);

    do
    {
        data.clear();
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

    cout << "\nYour input data: " << endl;
    print(data);

    return data;
}

bool checkMatrix(vector<vector<int>> data) // Time: O(n²)
{

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size(); j++)
        {
            if (i == j)
            {
                if (!(data[i][j] == 0))
                {
                    cout << "\n[ERROR]: Invalid data, there must be 0 between i == j" << endl;
                    cout << "Invaded data: " << data[i][j] << endl;
                    cout << "Please, enter your data again: " << endl;
                    return true;
                }
            }
            else
            {
                if (data[i][j] < -1 || data[i][j] == 0)
                {
                    cout << "\n[ERROR]: only numbers greater than 0 or numbers equal to -1 are accepted" << endl;
                    cout << "Invaded data: " << data[i][j] << endl;
                    cout << "Please, enter your data again: " << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

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

void print(vector<vector<int>> data) // Time: O(n²)
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

void print(vector<vector<vector<int>>> edges) // Time: O(n²)
{
    cout << "\nEdges (vertex, weight):" << endl;
    for (int i = 0; i < edges.size(); i++)
    {
        cout << "Node " << i + 1 << ": [ ";
        for (int j = 0; j < edges[i].size(); j++)
        {
            cout << "[";

            cout << edges[i][j][0] + 1 << "," << edges[i][j][1];

            cout << "] ";
        }
        cout << "]";
        cout << endl;
    }
    cout << endl;
}
