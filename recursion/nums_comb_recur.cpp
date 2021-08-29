#include <bits/stdc++.h>
using namespace std;

void numsPer(int i, vector<int> nums, vector<int> comb)
{
    if (comb.size() == 3)
    {
        for (int i : comb)
            cout << i;
        cout << endl;
        return;
    }
    for (int j = i; j < nums.size(); j++)
    {
        comb.push_back(nums[j]);
        numsPer(j + 1, nums, comb);
        comb.pop_back();
    }
}

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    numsPer(0, nums, {});
    return 0;
}