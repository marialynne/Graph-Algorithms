#include <bits/stdc++.h>
using namespace std;

/*

elements: 3
capacity: 4
[1,4]
[2,5]
[3,1]

output: [1,4]

[1,4] [2,5]

*/

tuple<vector<pair<int, int>>, int> getData();
void print(tuple<vector<pair<int, int>>, int> data);
void print(vector<vector<int>> matrix);

void getMatrix(vector<vector<int>> &matrix, int row, vector<pair<int, int>>); // Recursive
void knapsackProblem(tuple<vector<pair<int, int>>, int> data);                // Manager -> getMatrix -> PrintANS

int main()
{
    tuple<vector<pair<int, int>>, int> data; //= getData();

    get<0>(data).push_back({1, 2});
    get<0>(data).push_back({4, 3});
    get<0>(data).push_back({5, 6});
    get<0>(data).push_back({6, 7});
    get<1>(data) = 20;

    knapsackProblem(data);
    return 0;
}

tuple<vector<pair<int, int>>, int> getData()
{
    tuple<vector<pair<int, int>>, int> data;

    int n, element, weight, capacity;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++) // elements
    {
        cout << i + 1 << ") Element: ";
        cin >> element;
        cout << i + 1 << ") Weight: ";
        cin >> weight;

        get<0>(data).push_back({element, weight});

        cout << endl;
    }

    cout << "Enter n: ";
    cin >> capacity;
    get<1>(data) = capacity;

    return data;
}

void knapsackProblem(tuple<vector<pair<int, int>>, int> data)
{
    int elementsSize = get<0>(data).size();
    int capacity = get<1>(data);

    vector<vector<int>> matrix(elementsSize + 1, vector<int>(capacity + 1, 0));

    getMatrix(matrix, 1, get<0>(data));

    cout << endl;
    print(matrix);
}

void getMatrix(vector<vector<int>> &matrix, int row, vector<pair<int, int>> items)
{
    // matrix
    // row
    // vector<pair<int,int>>
    // [element,weight

    if (row >= matrix.size())
        return;

    pair<int, int> currentItem = items[row - 1];
    int residue;

    for (int columWeight = 0; columWeight < matrix[row].size(); columWeight++)
    {
        residue = columWeight - currentItem.second; // residue = 3 - 4; r = -1

        if (currentItem.second <= columWeight)
        {
            matrix[row][columWeight] = currentItem.first;
        }

        for (int previousRow = row - 1; previousRow > 0; previousRow--)
        {
            if (residue < 0)
                residue = columWeight;

            if (items[previousRow].second < residue)
            {
                matrix[row][columWeight] += items[previousRow].first;
            }
        }
    }

    getMatrix(matrix, row + 1, items);

    // print(matrix);
}

void print(tuple<vector<pair<int, int>>, int> data)
{
    for (auto i : get<0>(data))
    {
        cout << i.first << " " << i.second << endl;
    }
}

void print(vector<vector<int>> matrix)
{
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}