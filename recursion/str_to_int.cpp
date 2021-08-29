#include <bits/stdc++.h>
using namespace std;

int str_to_int(string str, int num, int i, int n)
{
    if (i == n)
        return num;
    int k = str[i] - '0';
    if (k >= 0 && k <= 9)
    {
        return str_to_int(str, (num * 10) + k, i + 1, n);
    }
}

int main()
{
    string s = "16386";
    int res = str_to_int(s, 0, 0, s.size());
    cout << res + 1 << endl;
    return 0;
}