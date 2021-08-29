#include<bits/stdc++.h>
using namespace std;


void creatingMatrix(int n,int m){
	// Adjacent Matrix
	int adj[n+1][n+1]={0};
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u][v] = 1;
		adj[v][u] = 1;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cout<< adj[i][j]<<" ";
		}
		cout<<endl;
	}
}

vector<int> bfsOfGraph(int v,vector<int> adj[]){
	vector<int> visited(v+1,0);
	vector<int> bfs;
	for(int i=1;i<v;i++){
		if(!visited[i]){
			queue<int> q;
			q.push(i);
			visited[i]=1;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				bfs.push_back(node);
				for(int j:adj[node]){
					if(!visited[j]){
						q.push(j);
						visited[j]=1;
					}
				}
			}
		}
	}
	return bfs;
}

void dfs(int node,vector<int>& visited,vector<int> adj[],vector<int>& res){
		res.push_back(node);
		visited[node]=1;
		for(int i:adj[node]){
			if(!visited[i]) dfs(i,visited,adj,res);
		}
	}
	
void dfsofGraph(int n,vector<int> adj[]){
	vector<int> res;
	vector<int> visited(n+1,0);
	for(int i=1;i<=n;i++){
		if(!visited[i])dfs(i,visited,adj,res);
	}
	for(int i=0;i<n;i++) cout<<res[i]<<" ";
}	

bool checkForCycle(int s,int V,vector<int> adj[],vector<int>& vis){
	vector<int> parent(V, -1);
	queue<pair<int,int>> q;
	vis[s]=true;
	q.push({s,-1});
	while(!q.empty()){
		int node = q.front().first;
		int par = q.front().second;
		q.pop();
		for(int it:adj[node]){
			if(!vis[it]){
				vis[it] = true;
				q.push({it,node});
			}else if(it != par) return true;
		}
	}
	return false;
}

bool isCycle(int V,vector<int> adj[]){
	vector<int> vis(V+1,0);
	for(int i=1;i<=V;i++){
		if(!vis[i])
		if(checkForCycle(i,V,adj,vis)) return true;
	}
	return false;
}

bool dfs_checkForCycle(int node,int parent,vector<int>& vis,vector<int> adj[]){
	vis[node]=1;
	for(auto it:adj[node]){
		if(!vis[it]){
			if(dfs_checkForCycle(it,node,vis,adj)) return true;	
		}	
		else if (it != parent) return true;
	}
	return false;
}

bool dfs_isCycle(int n,vector<int> adj[]){
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
		if(!vis[i]) if(dfs_checkForCycle(i,-1,vis,adj)) return true;
	}
	return false;
}
int main(){
	int n,m;
	n=4;	
	vector<int> adj[n+1];
	//,3,5,5,10,6,9,7,8  ,5,10,6,9,7,8,8,11
	vector<int> uvalues={1,2,3,4};
	vector<int> vvalues={2,3,4,2};
	m=uvalues.size();
	for(int i=0;i<m;i++){
		int u=uvalues[i],v=vvalues[i];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cout<<dfs_isCycle(n,adj);
	
	return 0;
}
