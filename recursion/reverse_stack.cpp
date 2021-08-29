#include <bits/stdc++.h>
using namespace std;

stack<int> s;

void reverse()
{
    if (s.size() == 0)
        return;
    reverse();
}

int main()
{
    for (int i = 1; i < 5; i++)
    {
        s.push(i);
    }
    int n = s.size();
}