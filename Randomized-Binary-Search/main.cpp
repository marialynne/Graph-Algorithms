#include <iostream>
#include <ctime>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<pair<int, int>> numbers)
{
    for (auto i : numbers)
        cout << " Value: " << i.first << "\tOriginal Index: " << i.second << endl;
}

int getRandom(int x, int y)
{
    srand(time(NULL));
    return (x + rand() % (y - x + 1));
}

void randomizedBinarySearch(vector<pair<int, int>> &numbers, int left, int right, int numberToSearch, vector<pair<int, int>> &ans)
{
    if (right >= left)
    {
        int mid = getRandom(left, right);

        if (numbers[mid].first == numberToSearch)
        {
            ans.push_back(numbers[mid]);

            int iLeft = 1, iRight = 1;

            while (ans[mid + iRight].first == numberToSearch)
            {
                ans.push_back(ans[mid + iRight]);
                iRight++;
            }

            while (ans[mid + iLeft].first == numberToSearch)
            {
                ans.push_back(ans[mid + iLeft]);
                iLeft++;
            }
        }

        if (numbers[mid].first > numberToSearch)
        {
            cout << numbers[mid].first << endl;
            randomizedBinarySearch(numbers, left, mid - 1, numberToSearch, ans);
        }

        randomizedBinarySearch(numbers, mid + 1, right, numberToSearch, ans);
    }
}

int main(void)
{
    vector<pair<int, int>> ans;
    vector<pair<int, int>> numbers = {
        {1, 0},
        {2, 1},
        {3, 2},
        {4, 3},
        {9, 4},
        {13, 5},
        {23, 6},
        {9, 7}};

    int numberToSearch = 9;

    sort(numbers.begin(), numbers.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool
         { return a.first > b.first; });

    randomizedBinarySearch(numbers, 0, numbers.size() - 1, numberToSearch, ans);

    cout << "Your search: " << endl;
    print(ans);

    /*  (ans.size() == 0) ? cout << "Element is not present in array\n"
                       : print(ans); */
    return 0;
}