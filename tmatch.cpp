#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,m,i=0,input;
	int sum=0;
	string s;
	vector<string> res;
	cin>>t;
	while(t){
		cin>>n;
		cin>>m;
		while(i<n){
			cin>>input;
			sum+=input;
			i++;
		}
			s=((n*(n+1)/2)==sum)?"no":"yes";
			i=0;
			res.push_back(s);
			t--;
	}
	for(auto s:res){
		cout<<s<<endl;
	}
	return 0;
}
