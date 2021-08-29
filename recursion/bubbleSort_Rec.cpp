#include <bits/stdc++.h>
using namespace std;

void b_sort(int *a, int n, int flag)
{
    int swap = 0;
    if (flag)
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                int temp = a[i];
                a[i] = a[i - 1];
                a[i - 1] = temp;
                swap = 1;
            }
        }
        b_sort(a, n, swap);
    }
    return;
}

void b_sort2(int *a, int n, int times)
{
    if (times == 0)
        return;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            int temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
        }
    }
    b_sort2(a, n, --times);
    return;
}

int main()
{
    int arr[] = {1, 5, 2, 6, 3, 4, 12, 11, 8, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    // b_sort(arr, n, 1);
    b_sort2(arr, n, n);
    cout << "Sorted Array:- ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    return 0;
}