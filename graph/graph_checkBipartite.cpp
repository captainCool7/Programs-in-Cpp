#include<bits/stdc++.h>
using namespace std;

class Graph{

private:
bool bipartiteDfs(int node,vector<int> adj[],int color[]){
	if(color[node] == -1) color[node]=1;
	for(int it:adj[node]){
		if(color[it]==-1){
			//*** set color for adjcent node ***
			color[it]=1-color[node];
			
			// Recursion
			if(!bipartiteDfs(it,adj,color)){
				return false;
			}
			//if color is similar to current node
		} else if(color[it] == color[node]) return false;
	}
	return true;
}

bool bipartiteBFS(int i,vector<int> adj[],int color[]){
	queue<int> q;
	q.push(i);
	color[i]=1;
	while(!q.empty()){
		int node = q.front();q.pop();
		for(int it:adj[node]){
			if(color[it]==-1){
				color[it]=1-color[node];
				q.push(it);	
			}else if(color[it] == color[node]) return false;
		}
	}
	return true;
}
public:
	
bool checkBipartiteBFS(vector<int> adj[],int n){
	int color[n+1];
	memset(color,-1,sizeof color);
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			if(!bipartiteBFS(i,adj,color)) return false;
		}
	}
	return true;
}
bool checkBipartite(vector<int> adj[],int n){
	int color[n+1];
	memset(color,-1,sizeof color);
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			if(!bipartiteDfs(i,adj,color)){
				return false;
			}
		}
	}
	return true;
}
};

int main(){
 	int u_values[]={1,2,3,4,5,5};
 	int v_values[]={2,3,4,5,6,7};
 	int v = sizeof(u_values)/sizeof(int);
 	int n = *max_element(v_values,v_values+v);
 	vector<int> adj[n+1];
 	for(int i=0;i<v;i++){
 		adj[u_values[i]].push_back(v_values[i]);
	 	adj[v_values[i]].push_back(u_values[i]);
	 }
	 Graph g = Graph();
	if(g.checkBipartiteBFS(adj,n)){
		cout<<"Bipartite Graph";
	}else{
		cout<<"Not a Bipartite Graph";
	}
 }
