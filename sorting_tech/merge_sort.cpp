#include <bits/stdc++.h>
using namespace std;

//write the merge sort function
void merge_sort(int *a, int n)
{
    int i, j, k;
    int temp[n];
    if (n < 2)
        return;
    merge_sort(a, n / 2);
    merge_sort(a + n / 2, n - n / 2);
    for (i = 0, j = n / 2; i < n / 2; i++, j++)
    {
        temp[i] = a[j];
    }
    for (i = n / 2, j = n - 1; i < n; i++, j--)
    {
        temp[i] = a[j];
    }
    for (i = 0, j = 0; i < n; i++, j++)
    {
        a[i] = temp[j];
    }
}

//write the merge sort function
// void merge_sort(int a[], int n, int m)
// {
//     int i, j, k;
//     int temp[n];
//     if (n < 2)
//         return;
//     merge_sort(a, n / 2, m);
//     merge_sort(a + n / 2, n - n / 2, m);
//     for (i = 0, j = n / 2; i < n / 2; i++, j++)
//     {
//         temp[i] = a[j];
//     }
//     for (i = n / 2, j = n - 1; i < n; i++, j--)
//     {
//         temp[i] = a[j];
//     }
//     for (i = 0, j = 0; i < n; i++, j++)
//     {
//         a[i] = temp[j];
//     }
// }

void merge(int *a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
        arr1[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = a[mid + 1 + i];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            a[k] = arr1[i];
            k++, i++;
        }
        else
        {
            a[k] = arr2[j];
            k++, j++;
        }
    }
    while (i < n1)
    {
        a[k] = arr1[i];
        k++, i++;
    }

    while (j < n2)
    {
        a[k] = arr2[j];
        k++, j++;
    }
}

void mergeSort(int *a, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

void merge2(int *a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int arr1[n1];
    int arr2[n2];
    for (int i = 0; i < n1; i++)
        arr1[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = a[mid + i + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            a[k] = arr1[i];
            k++, i++;
        }
        else
        {
            a[k] = arr2[j];
            k++, j++;
        }
    }
    while (i < n1)
    {
        a[k] = arr1[i];
        k++, i++;
    }
    while (j < n2)
    {
        a[k] = arr2[j];
        k++, j++;
    }
}

void mergeSort2(int *a, int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort2(a, l, mid);
        mergeSort2(a, mid + 1, r);
        merge2(a, l, mid, r);
    }
}

int main()
{
    int a[6] = {3, 5, 2, 1, 4, 6};
    mergeSort2(a, 0, 5);
    for (int t : a)
        cout << t << " ";
    return 0;
}