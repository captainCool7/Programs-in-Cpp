//https://unacademy.com/class/getting-started-with-c-for-cp-1/18JBNNMN
// https://www.spoj.com/problems/ANARC09A/
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s="}}}{{{}{";
	stack<int> st;
	int counter=0,ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='{') st.push('{');
		else{
			if(not st.empty()) st.pop();
			else counter++;
		}
	}
	if(st.size()>0){
		if(st.size()%2!=0){
			counter--;
			ans+=2;
		}
		ans+=st.size()/2;
	}
	if(counter>0){
		ans+=counter/2;
	}
	cout<<ans;
	return 0;	
}
