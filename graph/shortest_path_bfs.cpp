#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[],int n,int src){
    int dist[n];
    queue<int> q;
    for(int i=0;i<n;i++) dist[i] = INT_MAX;
    dist[src]=0;
    q.push(src);
    while(!q.empty()){
        int node  = q.front();
        q.pop();
        for(int it:adj[node]){
            if(dist[node]+1<dist[it]){
                dist[it] = dist[node]+1;
                q.push(it);
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }
}

int main(){
    int u_values[]={0,0,1,1,3,2,4,5,6,6,7};
    int v_values[]={1,3,2,3,4,6,5,6,7,8,8};
    int m = sizeof(v_values)/sizeof(int);
    int n = *max_element(v_values,v_values+m)+1;
    vector<int> adj[n];
    for(int i=0;i<m;i++){
        adj[u_values[i]].push_back(v_values[i]);
        adj[v_values[i]].push_back(u_values[i]);
    }

    BFS(adj,n,0);
    return 0;
}