#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<vector<int>> mat = {{1,2,3},{4,5,4},{7,8,9}};
//	vector<int> mat1 = {1,2,3,4,5,6,7,8,9};
//	for(auto i=mat.begin()+1;i<mat.end();i++){
//		auto v1 = *prev(i);
//		for(int n=0;n<v1.size();n++){
//			cout<<v1[n];
//		}
//	}
//	cout<<endl<<"Mat size: "<<mat1.size();
	vector<int> m1 = mat[1];
	cout<<m1.size();
	updateSubrectangle(0,0,2,1,5,&mat);
//	replace(m1.begin(),m1.end(),4,7);
//	for(int i:m1){
//		cout<<i;
//	}
	return 0;
}
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue,auto &matx) {
        int rowSize = matx[0].size();
        for(int i=row1;i<=row2;i++){
            for(int j=col1;j==col2 and i==row2;j=(j+1)%rowSize){
                matx[i][j]=newValue;
            }
        }
    }
