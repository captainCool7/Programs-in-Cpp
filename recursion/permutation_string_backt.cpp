#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
void per_back(string str,int j){
	if(str.size()-1==j){
		cout<<str<<endl;
		return;
	}
	for(int i=j;i<str.size();i++){
		cout<<"1. Swapping "<<str[i]<<" "<<str[j]<<endl;
		swap(str[i],str[j]);
		per_back(str,j+1);
		cout<<"2. Swapping "<<str[i]<<" "<<str[j]<<endl;
		swap(str[i],str[j]);
	}
}
int main(){
	per_back("ABC",0);
	return 0;
}
