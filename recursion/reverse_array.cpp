#include <bits/stdc++.h>
using namespace std;

void reversePrint(int *a, int i, int n)
{
    if (i == n)
        return;
    reversePrint(a, i + 1, n);
    // cout << a[i];
}

void swap(int *i, int *n)
{
    *i = *i + *n;
    *n = *i - *n;
    *i = *i - *n;
}

void reverse(int *a, int i, int n)
{
    if (i == n)
        return;
    swap(a[i], a[n - 1]);
    reverse(a, i + 1, n - 1);
}

int main()
{
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    // reversePrint(arr, 0, n);
    reverse(arr, 0, n);
    for (int i : arr)
    {
        cout << i;
    }
    return 0;
}