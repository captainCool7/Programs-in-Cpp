#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		bool checkCycle(int node,vector<int> adj[],int visited[],int cvisit[]){
			visited[node]=1;
			cvisit[node]=1;
			for(auto it:adj[node]){
				if(!visited[it]){
					if(checkCycle(it,adj,visited,cvisit)) return true;
				}else if(cvisit[it]) return true;
			}
			cvisit[node]=0;
			return false;
		}
	public:
		bool isCycle(int n,vector<int> adj[]){
			int visited[n+1];
			int currvisited[n+1];
			memset(visited,0,sizeof visited);
			memset(currvisited,0,sizeof currvisited);
			for(int i=1;i<=n;i++){
				if(visited[i]==0){
					if(checkCycle(i,adj,visited,currvisited)) return true;
				}					
			}
			return false;
		}
};

int main(){
	// ,7,7,8,9  ,2,8,9,7
	int u_values[] ={1,2,3,3,4,6};
	int v_values[] ={2,3,4,6,5,5};
	int v_size=sizeof(v_values)/sizeof(int);
	int n = *max_element(v_values,v_values+v_size);
	vector<int> adj[n+1];
	for(int i=0;i<v_size;i++){
		adj[u_values[i]].push_back(v_values[i]);
	}
	Graph g = Graph();
//	int* p=v_values;
//	int* c =p;
//	cout<<*(++c);
	if(g.isCycle(n,adj))cout<<"Cycle is present";
	else cout<<"No cycle is present";	
}
