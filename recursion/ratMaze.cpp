#include<iostream>
#include<vector>
using namespace std;
int totalPath=0;
bool isitSafe(int i,int j,int n,vector<vector<bool>> &visited){
	return i>=0 and j>=0 and i<n and j<n and visited[i][j]==false;
}
void helper(int i,int j,int n,vector<vector<int>> &grid,vector<vector<bool>> &visited){
	if(i==n-1 and j==n-1){
		totalPath+=1;
		return;
	}
	if(not isitSafe(i,j,n,visited)){
		return;
	}
	visited[i][j]=true;
	if(i+1<n and grid[i+1][j]==0) helper(i+1,j,n,grid,visited); //down
	
	if(i-1>=0 and grid[i-1][j]==0) helper(i-1,j,n,grid,visited);//up
	
	if(j+1<n and grid[i][j+1]==0) helper(i,j+1,n,grid,visited);//right
	
	if(j-1>=0 and grid[i][j-1]==0) helper(i,j-1,n,grid,visited);//left
	visited[i][j]=false;
	return;
	
}
int countPath(vector<vector<int>> &grid){
	int n=grid.size();
	vector<vector<bool>> visited(n,vector<bool> (n,false));
	helper(0,0,n,grid,visited);
	return totalPath;
}
int main(){
	vector<vector<int>> grid={{0,0,1,0},{0,1,1,1},{0,0,0,0},{1,1,0,0}};
	cout<<countPath(grid);
	return 0;
}
