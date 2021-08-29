#include <bits/stdc++.h>
using namespace std;
void getActivities(vector<int> s,vector<int> f){
	vector<pair<int,int>> ans;
	//sorting the Activity pairs
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	//selecting the 1st activity
	//because it is first one to end
	for(int i=0;i<s.size();i++){
		pq.push(make_pair(f[i],s[i]));
	}
	auto it = pq.top();
	int start = it.second;
	int end = it.first;
	pq.pop();
	ans.push_back(make_pair(start,end));
	while(!pq.empty()){
		it = pq.top();
		pq.pop();
		//check start time is >= previous end time
		if(it.second>=end){
			start = it.second;
			end = it.first;
			ans.push_back(make_pair(start,end));
		}
	}
	//printing activity
	for(auto itr=ans.begin();itr!=ans.end();itr++){
		cout<<(*itr).first<<", "<<(*itr).second<<endl;
	}
}
int main(){
	vector<int>s = {1, 3, 0, 5, 8, 5};
    vector<int>f = {2, 4, 6, 7, 9, 9};
    getActivities(s,f);
	return 0;
}
