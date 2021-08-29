#include <bits/stdc++.h>
using namespace std;

int swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void rearrange(int *a, int n)
{
    int i = 0, j = 0;
    bool flag = 0;
    for (int i = 0; i < n; i++)
    {
        flag = !flag;
        if (flag)
        {
            if (a[i] > 0)
                continue;
            else
            {
                j = i + 1;
                while (a[j] <= 0 and j < n)
                    j++;
                if (j == n)
                    return;
                swap(a[j], a[i]);
            }
        }
        else
        {
        }
    }
}

int main()
{
    int a = 5, b = 3;
    swap(a, b);
    cout << a << " " << b;
    return 0;
}