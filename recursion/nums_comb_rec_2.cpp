#include <bits/stdc++.h>
using namespace std;

void allCombUtility(int arr[], int data[], int start, int end, int idx, int r)
{
    if (idx == r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }

    for (int i = start; i <= end and end - i + 1 >= r - idx; i++)
    {
        data[idx] = arr[i];
        allCombUtility(arr, data, i + 1, end, idx + 1, r);
    }
}

void allPossibleCombinations(int arr[], int r, int n)
{
    int data[r];
    allCombUtility(arr, data, 0, n - 1, 0, r);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3, size;
    size = sizeof(arr) / sizeof(int);
    allPossibleCombinations(arr, r, size);
}