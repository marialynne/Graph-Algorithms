#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
vector<vector<string>> transformData(string path);
vector<vector<string>> readData(string path);
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
    vector<vector<string>> data = readData(path);
    return data;
}

vector<vector<string>> readData(string path) // Time: O(n)
{
    string line;
    ifstream myfile(path);
    vector<string> lines;
    vector<vector<string>> matrix;

    if (myfile.is_open())
    {
        if (myfile.peek() == std::ifstream::traits_type::eof())
        {
            cout << "\n\t<< The file is empty >> ";
            exit(0);
        }

        while (getline(myfile, line))
        {
            std::istringstream iss(line);
            string number;
            while (iss >> number)
                lines.push_back(number);
            matrix.push_back(lines);
            lines.clear();
        }
        myfile.close();
    }
    else
    {
        cout << "\n\t<< File does not exist >>";
        exit(0);
    }

    return matrix;
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