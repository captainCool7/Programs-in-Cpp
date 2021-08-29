//https://www.geeksforgeeks.org/binary-search/

#include <bits/stdc++.h>
using namespace std;

bool rec_binary_search(int arr[], int l, int r, int t)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        if (t == arr[mid])
            return true;
        else if (t < arr[mid])
            return rec_binary_search(arr, l, mid - 1, t);
        else
            return rec_binary_search(arr, mid + 1, r, t);
    }
    return false;
}

int main()
{
    int arr[] = {2, 4, 7, 8, 10, 12, 15, 16, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (rec_binary_search(arr, 0, n, 11))
        cout << "Number is Present!! ";
    else
        cout << "Number is not Present";
}