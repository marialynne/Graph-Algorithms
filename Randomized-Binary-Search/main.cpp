#include <iostream>
#include <ctime>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <regex>
#include <stdlib.h>
using namespace std;

bool regexNumber(string numb) // Time: O(1)
{
    const regex expReg("^[0-9]+$");
    return regex_match(numb, expReg);
}

bool regexFloat(string numb) // Time: O(1)
{
    const regex expReg("^[+-]?([0-9]*[.])?[0-9]+$");
    return regex_match(numb, expReg);
}

void print(vector<pair<float, int>> numbers) // Time: O(n)
{
    for (auto i : numbers)
        std::cout << " Value: " << i.first << "\tOriginal Index: " << i.second << "\n";
}

int getRandom(int x, int y) // Time: O(1)
{
    srand(time(NULL));
    return (x + rand() % (y - x + 1));
}

vector<pair<float, int>> getNeighbors(int index, vector<pair<float, int>> numbers, vector<pair<float, int>> ans) // Time: O(n)
{
    int iLeft = 1, iRight = 1;
    ans.push_back(numbers[index]);

    while (numbers[index - iLeft].first == numbers[index].first)
    {
        ans.push_back(numbers[index - iLeft]);
        iLeft++;
    }

    while (numbers[index + iRight].first == numbers[index].first)
    {
        ans.push_back(numbers[index + iRight]);
        iRight++;
    }

    return ans;
}

vector<pair<float, int>> randomizedBinarySearch(vector<pair<float, int>> numbers, int left, int right, float numberToSearch, vector<pair<float, int>> ans) // Time: O(log N)
{
    if (right >= left)
    {
        int mid = getRandom(left, right);

        if (numbers[mid].first == numberToSearch)
            return getNeighbors(mid, numbers, ans);

        if (numbers[mid].first > numberToSearch)
            return randomizedBinarySearch(numbers, left, mid - 1, numberToSearch, ans);
        return randomizedBinarySearch(numbers, mid + 1, right, numberToSearch, ans);
    }
    return {};
}

int main(void)
{
    vector<pair<float, int>> ans;
    vector<pair<float, int>> numbers;
    /* = {
       {1, 0},
       {2, 1},
       {3, 2},
       {4, 3},
       {9, 4},
       {13, 5},
       {23, 6},
       {9, 7}}; */

    float numberToSearch;
    int n;

    string input;
    std::cout << "Type N: ";
    cin >> input;

    while (!regexNumber(input))
    {
        std::cout << "N must be integer positive number, try again...\n";
        std::cout << "Type N: ";
        cin >> input;
    }

    n = stoi(input);

    for (int i = 0; i < n; i++)
    {
        std::cout << "(" << i + 1 << "/" << n << "): ";
        cin >> input;

        if (regexFloat(input))
            numbers.push_back({stof(input), i + 1});
        else
        {
            i--;
            std::cout << "\nInvalid entry. Retry again...\n";
        }
    }

    std::cout << "Type the number to search: ";
    cin >> input;
    while (!regexFloat(input))
    {
        std::cout << "\nInvalid entry. Retry again...\n";
        std::cout << "Type the number to search: ";
        cin >> input;
    }

    numberToSearch = stof(input);

    std::sort(numbers.begin(), numbers.end(), [](const pair<float, int> &a, const pair<float, int> &b) -> bool
              { return a.first < b.first; });

    ans = randomizedBinarySearch(numbers, 0, numbers.size() - 1, numberToSearch, ans);

    std::cout << "Your search:\n";

    if (ans.size())
        print(ans);
    else
        std::cout << "Element is not present in array\n";

    return 0;
}