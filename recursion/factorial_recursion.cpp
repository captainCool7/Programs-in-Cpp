#include <bits/stdc++.h>
using namespace std;

int helper(int n)
{
    if (n == 1)
        return 1;
    return n * helper(n - 1);
}

// Memorization
vector<int> v(10, -1);
int fibo(int n)
{
    if (n < 2)
        return n;
    if (v[n] != -1)
        return v[n];
    v[n] = fibo(n - 2) + fibo(n - 1);
    return v[n];
}

int main()
{
    cout << fibo(6);
    return 0;
}

//0 1 1 2 3 5 8 13