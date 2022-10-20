#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> getData();
void print(vector<vector<int>> data);
void print(vector<tuple<int, int, int, vector<int>>> nodes);
vector<tuple<int, int, int, vector<int>>> getEdges(vector<vector<int>> matrix);
void graphColoring(vector<tuple<int, int, int, vector<int>>> nodes);
bool checkMatrix(vector<vector<int>> data);

int main()
{
    vector<vector<int>> matrix = getData();
    /*vector<vector<int>> matrix = {{0, 1, 0, 0, 1},
                                  {1, 0, 0, 0, 1},
                                  {0, 0, 0, 1, 1},
                                  {0, 0, 1, 0, 0},
                                  {0, 1, 1, 1, 0}}
    */
    vector<tuple<int, int, int, vector<int>>> nodes = getEdges(matrix);
    graphColoring(nodes);

    return 0;
}

void graphColoring(vector<tuple<int, int, int, vector<int>>> nodes) // Time: O(n²)
{
    vector<int> colors = {1, 2, 3, 4};
    int nodeToSearch;
    int eachColor;

    for (int i = 0; i < nodes.size(); i++)
    {
        int colorIndex = 0;

        for (int j = 0; j < get<3>(nodes[i]).size(); j++)
        {
            nodeToSearch = get<3>(nodes[i])[j];
            if (get<2>(nodes[nodeToSearch]) == colors[colorIndex])
                colorIndex++;
        }
        get<2>(nodes[i]) = colors[colorIndex];
    }

    print(nodes);
}

vector<tuple<int, int, int, vector<int>>> getEdges(vector<vector<int>> matrix) // Time: O(n²)
{
    vector<tuple<int, int, int, vector<int>>> nodes; // node - count

    for (int row = 0; row < matrix.size(); row++)
    {
        int count = 0;
        vector<int> edges;

        for (int colum = 0; colum < matrix[row].size(); colum++)
        {
            if (matrix[row][colum] == 1)
            {
                count++;
                edges.push_back(colum);
            }
        }

        nodes.push_back({row, count, 0, edges});
    }

    sort(nodes.begin(), nodes.end(), [](const tuple<int, int, int, vector<int>> &a, const tuple<int, int, int, vector<int>> &b) -> bool
         { return get<0>(a) > get<0>(a); });

    // print(nodes);
    return nodes;
}

vector<vector<int>> getData() // Time: O(n²)
{
    vector<vector<int>> data;
    char nchar[100];
    int n, input;
    regex regexN("([2-9])+");

    cout << "Please, enter n (number of nodes): ";
    cin.getline(nchar, 100);

    while (!regex_match(nchar, regexN)) // Here should go n to verification (positive integer)
    {
        cout << "[ERROR]: n must be a number greater than 1. \nPlease, enter n (number of nodes): ";
        cin.getline(nchar, 100);
    }

    n = stoi(nchar);

    cout << "Please, enter your data (number per row  separated with space): " << endl;

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
                if (data[i][j] < 0)
                {
                    cout << "\n[ERROR]: Negative numbers are not accepted" << endl;
                    cout << "Invaded data: " << data[i][j] << endl;
                    cout << "Please, enter your data again: " << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

void print(vector<vector<int>> data) // Time: O(n²)
{
    for (auto i : data)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void print(vector<tuple<int, int, int, vector<int>>> nodes) // Time: O(n²)
{
    for (int i = 0; i < nodes.size(); i++)
    {
        cout << "Node: " << get<0>(nodes[i]) << "   Degree: " << get<1>(nodes[i]) << "   Color: " << get<2>(nodes[i]) << "\tEdges: [ ";
        for (auto j : get<3>(nodes[i]))
            cout << j << " ";
        cout << "]\n";
    }
}