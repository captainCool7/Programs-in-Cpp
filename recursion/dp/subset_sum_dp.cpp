#include <bits/stdc++.h>
using namespace std;

bool getResult(int arr[], int sum, int n)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // cout << i << " " << j << endl;
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int arr[] = {2, 3, 7, 8, 10};
    // int arr[] = {1, 11, 3, 7, 5};
    int sum = 14;
    int n = sizeof(arr) / sizeof(int);
    cout << "Numbers with sum is present: " << getResult(arr, sum, n) << endl;
    return 0;
}