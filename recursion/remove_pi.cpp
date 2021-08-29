#include <bits/stdc++.h>
using namespace std;

string removePi(string s, string &res, int i, int n)
{
    if (i >= n)
        return res;

    if (s[i] == 'p' and s[i + 1] == 'i')
    {
        res += "3.14";
        removePi(s, res, i + 2, n);
    }
    else
    {
        res += s[i];
        removePi(s, res, i + 1, n);
    }
    return res;
}

int main()
{
    string s = "pippppiiiipi";
    int n = sizeof(s) / sizeof(s[0]);
    string res = "";
    cout << removePi(s, res, 0, s.size());
    // cout<<replace( s.begin(), s.end(), "pi", "3.14")
    return 0;
}