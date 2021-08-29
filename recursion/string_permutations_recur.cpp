#include <bits/stdc++.h>
using namespace std;

void stringPer(string s, string ros)
{
    if (!s.size())
    {
        cout << ros << endl;
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        string temp = s.substr(0, i) + s.substr(i + 1);
        stringPer(temp, ros + c);
    }
}

int main()
{
    stringPer("ABC", "");
}