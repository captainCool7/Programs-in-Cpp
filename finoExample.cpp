#include<bits/stdc++.h>
#define COUNT 5
using namespace std;

vector<int> res(COUNT,-1);
int getfibo(int n){
	if(res[n]!=-1) return res[n];
	else{
		res[n]=getfibo(n-1)+getfibo(n-2);
		return res[n];	
	} 
}
int main(){
	res[0]=0;
	res[1]=1;
	res[2]=1;
	getfibo(5);
	cout<<res[5];
	return 1;
}
