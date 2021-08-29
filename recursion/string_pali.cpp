#include <bits/stdc++.h>
using namespace std;

bool isPallindrome(string s)
{
    cout << s << " ";
    if (s == "")
        return true;
    else if (s[0] != s[s.size() - 1])
        return false;
    return isPallindrome(s.substr(1, s.size() - 2));
}

bool isPallindrome2(string s, int i = 0)
{
    int n = s.size();
    if (i >= n / 2)
        return true;
    if (s[i] == s[n - i - 1])
        return isPallindrome2(s, ++i);
    return false;
}

int main()
{
    if (isPallindrome2("madam"))
        cout << "It's a Pallindrome";
    else
        cout << "It's not a Pallindrome";
    return 0;
}