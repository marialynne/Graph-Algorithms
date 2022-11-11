// C++ program to implement recursive
// randomized algorithm.
#include <iostream>
#include <ctime>
using namespace std;

// To generate random number
// between x and y ie.. [x, y]
int getRandom(int x, int y)
{
    srand(time(NULL));
    return (x + rand() % (y - x + 1));
}

// A recursive randomized binary search function.
// It returns location of x in
// given array arr[l..r] is present, otherwise -1
int randomizedBinarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = getRandom(l, r);

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return randomizedBinarySearch(arr, l, mid - 1, x);
        return randomizedBinarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

// Driver code
int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = randomizedBinarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d", result);
    return 0;
}
