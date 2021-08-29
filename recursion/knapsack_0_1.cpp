#include <bits/stdc++.h>
using namespace std;

// int dp[50][100];

//Recursion Only
//----------------------------------------------------------------
// int knapsack(int value[], int weight[], int capacity, int n)
// {
//     if (n == 0 or weight == 0)
//         return 0;
//     if (weight[n - 1] <= capacity)
//         return max(value[n - 1] + knapsack(value, weight, capacity - weight[n - 1], n - 1),
//                    knapsack(value, weight, capacity, n - 1));
//     else
//         return knapsack(value, weight, capacity, n - 1);
// }

//Recursion + Memorization
//----------------------------------------------------------------
// int knapsack(int value[], int weight[], int capacity, int n)
// {
//     if (n == 0 or weight == 0)
//         return 0;
//     //If value exists in dp return that value
//     if (dp[n][capacity] != -1)
//         return dp[n][capacity];
//     if (weight[n - 1] <= capacity)
//     {
//         //storing the value in dp,so that we don't have to store it again
//         dp[n][capacity] = max(value[n - 1] + knapsack(value, weight, capacity - weight[n - 1], n - 1),
//                               knapsack(value, weight, capacity, n - 1));
//         return dp[n][capacity];
//     }
//     else
//     {
//         dp[n][capacity] = knapsack(value, weight, capacity, n - 1);
//         return dp[n][capacity];
//     }
// }

int knapsack(int value[], int weight[], int capacity, int n)
{
    int dp[n + 1][capacity + 1];
    for (int i = 0; i < capacity + 1; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {

            if (weight[i - 1] <= j)
            {
                cout << "in" << endl;
                dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][capacity];
}

int main()
{
    int value[] = {1, 3, 4, 5};
    int weight[] = {1, 2, 4, 7};
    int capacity = 7;
    int n = 4;
    // memset(dp, -1, sizeof dp);
    cout << knapsack(value, weight, capacity, n);
}