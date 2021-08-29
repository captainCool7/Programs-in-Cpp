#include<bits/stdc++.h>
using namespace std;

bool topoSort(int n,vector<int> adj[]){
	queue<int> q;
	vector<int> indegree(n,0);
	for(int i=0;i<n;i++){
		for(int& it:adj[i]) indegree[it]++;
	}
	
	for(int i=0;i<n;i++){
		if(!indegree[i]) q.push(i);
	}
	int count=0;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		count++;
		for(int& it:adj[node]){
			indegree[it]--;
			if(!indegree[it]) q.push(it);
		}
	}
	return count!=n;
}

int main(){
//	int u_values[]={2,3,4,4,5,5};
//	int v_values[]={3,1,1,0,2,0};
	int u_values[]={0,1,2,3,4};
	int v_values[]={1,2,3,4,5};
	int n=5;
	vector<int> adj[n];
	for(int i=0;i<n;i++){
		adj[u_values[i]].push_back(v_values[i]);
	}
	
	 if(topoSort(n,adj)) cout<<"Graph has Cycle";
	 else cout<<"Nooo";
	
	return 0;
}
