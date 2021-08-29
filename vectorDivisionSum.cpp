#include<iostream>
#include<vector>
using namespace std;
int main(){
	int TC,n,l,r;
	cin>>n;
	vector<int> vec(n,0);
	cin>>TC;
	while(TC--){
		cin>>l>>r;
		vec[l]++;
		if(r+1<n) vec[r+1]--;
	}
	for(int i=1;i<n;i++){
		vec[i]+=vec[i-1];
	}
	for(int i:vec) cout<<i<<" ";
	return 0;
}
