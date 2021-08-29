#include<iostream>
#include<string>
using namespace std;
int main(){
	int t,num,cnt;
	string s;
	cin>>t;
	while(t>0){
		cnt=0;
		cin>>num>>s;
		for(j=num-1;j>=0;j--){
			if(s[j]==')'){
				cnt++;
			}else{
				break;
			}
		}
		cout<<cnt;
		if(cnt>(num-cnt)){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
		t--;
	}
}
