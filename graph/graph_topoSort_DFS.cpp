#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node,vector<int> &visited,vector<int> adj[],stack<int> &st){
	visited[node]=1;
	for(int it:adj[node]){
		if(!visited[it]) findTopoSort(it,visited,adj,st);
	}
	st.push(node);
}

vector<int> topoSort(int n,vector<int> adj[]){
	vector<int> visited(n,0);
	stack<int> st;
	for(int i=0;i<n;i++){
		if(!visited[i])
			findTopoSort(i,visited,adj,st);		
	}
	
	vector<int> res;
	while(!st.empty()){
		res.push_back(st.top());
		st.pop();
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
