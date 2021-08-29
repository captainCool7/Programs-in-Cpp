#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> res;
	bool val=false;
	int i=3;
	while(i--){
		int j;
		cin>>j;
		val=(val or count(res.begin(),res.end(),j));
	}
	if(val) cout<<"Yes";
	else cout<<"No";
}
