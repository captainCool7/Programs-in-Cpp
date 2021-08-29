#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> m, vector<int> h) {
	sort(m.begin(), m.end());
	sort(h.begin(), h.end());
	int m_size = m.size();
	int h_size = h.size();
	if (m_size != h_size) return -1;
	int max = 0;
	for (int i = 0; i < m_size; i++) {
		if (max < abs(m[i] - h[i]))
			max = abs(m[i] - h[i]);
	}
	return max;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> m {4, -4, 2};
	vector<int> h{4, 0, 5};
	cout << helper(m, h);
	return 0;
}