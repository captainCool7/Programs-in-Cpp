// Kahn's Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int n,vector<int> adj[]){
	int i;
	vector<int> res;
	queue<int> q;
	int indegree[n];
	memset(indegree,0,sizeof indegree);
	for(i=0;i<n;i++){
		for(int it:adj[i]) indegree[it]++;
	}
	
	for(i=0;i<n;i++){
		if(!indegree[i]) q.push(i);
	}
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		res.push_back(node);
		for(int it: adj[node]){
			indegree[it]--;
			if(!indegree[it]) q.push(it);
		}
	}
	return res;
}

int main(){
	int u_values[]={2,3,4,4,5,5};
	int v_values[]={3,1,1,0,2,0};
	int n=6;
	vector<int> adj[n];
	for(int i=0;i<n;i++){
		adj[u_values[i]].push_back(v_values[i]);
	}
	
	vector<int> topo= topoSort(n,adj);
	for(int i:topo){
		cout<<i<<" ";	
	}
	return 0;
}
