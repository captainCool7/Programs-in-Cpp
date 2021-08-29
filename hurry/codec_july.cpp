#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("../input.txt", "r", stdin);
	freopen("../output.txt", "w", stdout);
#endif
	// your code goes here
	int t;
	long long int n, k;
	cin >> t;
	vector<long long int> v;
	while (t--)
	{
		cin >> n >> k;
		while (n--)
		{
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		int p = 0;
		for (int i = 0; i < 64; i++)
		{
			int num = pow(2, p);
		}
	}
	return 0;
}
