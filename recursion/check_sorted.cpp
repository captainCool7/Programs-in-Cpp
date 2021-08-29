#include <bits/stdc++.h>
using namespace std;

bool isSorted(int *a, int i, int n)
{
    if (i == n - 1)
        return true;
    if (a[i] > a[i + 1])
        return false;
    return isSorted(a, i + 1, n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 15, 6, 7, 8, 9, 10};
    cout << isSorted(arr, 0, 10) << endl;
    return 0;
}