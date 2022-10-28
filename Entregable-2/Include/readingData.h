#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
vector<vector<string>> transformData(string path);
vector<string> readData(string path);
vector<vector<string>> getMatrix1();
vector<vector<string>> getMatrix2();
void print(vector<vector<string>> matrix);
string removeSpaces(string str);

vector<vector<string>> getMatrix1() // Time: O(1)
{
    string pathMatrix1 = "Input/distances.txt";
    vector<vector<string>> data = transformData(pathMatrix1);

    return data;
}

vector<vector<string>> getMatrix2() // Time: O(1)
{
    string pathMatrix2 = "Input/transmissionCapabilities.txt";
    vector<vector<string>> data = transformData(pathMatrix2);

    return data;
}

vector<vector<string>> transformData(string path) // Time: O(n²)
{
    vector<string> data = readData(path);
    vector<vector<string>> matrix;
    vector<string> row;
    string element;

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].length(); j++)
        {
            element += data[i][j];
            if (data[i][j] == ' ' || j == data[i].length() - 1)
            {
                row.push_back(string(removeSpaces(element)));
                element = "";
            }
        }
        matrix.push_back(row);
        row.clear();
    }
    return matrix;
}

vector<string> readData(string path) // Time: O(n)
{
    string line;
    ifstream myfile(path);
    vector<string> lines;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
            lines.push_back(line);

        myfile.close();
    }

    return lines;
}

string removeSpaces(string str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}

void print(vector<vector<string>> matrix)
{
    for (auto i : matrix)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
}