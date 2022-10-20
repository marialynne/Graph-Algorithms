//#include <bits/stdc++.h>
#include <regex>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

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
void print(set<set<pair<int, int>>> ans);
bool nonReapetElements(int sizeElementsID, int sizeData);
int validation(string msg);
void getMatrix(vector<vector<int>> &matrix, int row, vector<pair<int, int>> items);
void knapsackProblem(tuple<vector<pair<int, int>>, int> data);

int main()
{
    tuple<vector<pair<int, int>>, int> data = getData();

    /* get<0>(data).push_back({1, 2});
    get<0>(data).push_back({4, 3});
    get<0>(data).push_back({5, 6});
    get<0>(data).push_back({6, 7}); */

    // get<0>(data).push_back({1, 4});
    // get<0>(data).push_back({2, 5});
    // get<0>(data).push_back({3, 1});

    // get<1>(data) = 20;

    knapsackProblem(data);
    return 0;
}

int validation(string msg) // Time: O(n)
{
    regex regexN("([1-9]{1})|([1-9]{1}[0-9]+)");
    char input[100];

    cout << msg;
    cin.getline(input, 100);

    while (!regex_match(input, regexN))
    {
        cout << "\n";
        cout << "[ERROR]: Number must be a number greater than 0." << endl;
        cout << msg;
        cin.getline(input, 100);
    }

    return stoi(input);
}

bool nonReapetElements(int sizeElementsID, int sizeData) // Time: O(1)
{
    if (sizeElementsID != sizeData)
    {
        cout << "Tas wey mijo, no puedes repetir valores en los elementos\n\n";
    }
    return sizeElementsID != sizeData;
}

tuple<vector<pair<int, int>>, int> getData() // Time: O(n²)
{
    tuple<vector<pair<int, int>>, int> data;
    int n, element, weight, capacity;
    string msgN = "Please, enter n: ", msgElement = "Element: ", msgWeight = "Weight: ", msgCapacity = "Enter Capacity: ";
    set<int> elementsID;

    n = validation(msgN);
    cout << endl;

    do
    {
        get<0>(data).clear();

        for (int i = 0; i < n; i++)
        {
            element = validation(msgElement);
            weight = validation(msgWeight);

            cout << endl;

            get<0>(data).push_back({element, weight});
            elementsID.insert(element);
        }

    } while (nonReapetElements(elementsID.size(), get<0>(data).size()));

    capacity = validation(msgCapacity);
    get<1>(data) = capacity;

    return data;
}

void knapsackProblem(tuple<vector<pair<int, int>>, int> data) // Time: O(n²)
{
    int elementsSize = get<0>(data).size();
    int capacity = get<1>(data);

    vector<vector<int>> matrix(elementsSize + 1, vector<int>(capacity + 1, 0));

    getMatrix(matrix, 1, get<0>(data));

    cout << "\nMatrix: " << endl;
    print(matrix);

    int maxItem = matrix[elementsSize][capacity];

    cout << "\nThe optimal solution: " << maxItem << endl;

    set<set<pair<int, int>>> solutions;
    set<pair<int, int>> ans;

    do
    {
        int accumItems = 0;
        int accumWeight = 0;

        for (auto i : get<0>(data))
        {
            if (accumItems <= maxItem)
            {
                accumItems += i.first;
                accumWeight += i.second;

                ans.insert(i);

                if (accumItems == maxItem && accumWeight <= get<1>(data))
                {
                    solutions.insert(ans);
                }
            }
        }

        ans.clear();

    } while (next_permutation(get<0>(data).begin(), get<0>(data).end()));

    print(solutions);
}

void getMatrix(vector<vector<int>> &matrix, int row, vector<pair<int, int>> items) // Time: O(n²)
{
    if (row >= matrix.size())
        return;

    for (int colWeight = 0; colWeight < matrix[row].size(); colWeight++)
    {
        int remainingWeight = colWeight;

        for (int item = row - 1; (item >= 0 && remainingWeight >= 0); item--)
        {
            if (items[item].second <= remainingWeight)
            {
                matrix[row][colWeight] += items[item].first;
                remainingWeight -= items[item].second;
            }
        }

        if (matrix[row][colWeight] < matrix[row - 1][colWeight])
            matrix[row][colWeight] = matrix[row - 1][colWeight];
    }

    getMatrix(matrix, row + 1, items);
}

void print(tuple<vector<pair<int, int>>, int> data) // Time: O(n)
{
    for (auto i : get<0>(data))
    {
        cout << i.first << " " << i.second << endl;
    }
}

void print(vector<vector<int>> matrix) // Time: O(n²)
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

void print(set<set<pair<int, int>>> ans) // Time: O(n²)
{
    cout << "Items:" << endl;

    for (auto i : ans)
    {
        for (auto j : i)
            cout << "\t[" << j.first << ", " << j.second << "]" << endl;
    }
}