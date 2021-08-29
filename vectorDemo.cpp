#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

bool fun(int x,int y){
	return x>y;
}
template <typename T>
void print(T A){
	for(int x:A){
		cout<<x<<" ";
	}
	cout<<endl;
}
void VectorDemo(){
	/*
	For Array
	int A1[]={11,22,33,44,55};
	for(int x:A1){
		cout<<x<<" ";
	}*/
	vector<int> A ={13,2,11,4};
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(100);
	A.push_back(107);
	sort(A.begin(),A.end());
	bool present = binary_search(A.begin(),A.end(),2);
	cout<<present<<endl;	
	auto it1 = lower_bound(A.begin(),A.end(),100);//>=
	auto it2 = upper_bound(A.begin(),A.end(),100);//>
	cout<<*it1<<" "<<*it2<<endl;
	cout<<it2-it1<<endl;//4
	vector<int>::iterator it;
//	for(it=A.begin();it!=A.end();it++){
//		cout<<*it<<" ";
//	}
	print(A);
	sort(A.begin(),A.end(),fun);
	print(A);
	reverse(A.begin(),A.end());
	print(A);
	
}
void SetDemo(){
	set<int> S;
	S.insert(1);
	S.insert(2);
	S.insert(-1);
	S.insert(-10);
	print(S);
	set<int>::iterator it = S.find(1);
	if(it == S.end()){
		cout<<"Number is not available\n";
	}else{
		cout<<"present\n";
	}
	auto it1 = S.lower_bound(-1);
	auto it2 = S.upper_bound(1);
	cout<<*it1<<" "<<*it2<<endl;
	auto it3 = S.erase(1);
	cout<<it3<<endl;
	print(S);
}
void MapDemo(){
	map<int,int> A;
	A[1] = 100;
	A[2] = 200;
	A[3] = 300;
	A[100000] = 400;
	map<char,int> cnt;
	string s = "abhishek";	
}
int main(){
	/*vector<int> V={1,2,3,4,5,6,8,9,10};
	make_heap(V.begin(),V.end());
	print(V);
	V.push_back(7);
	push_heap(V.begin(),V.end());
	print(V);*/
	//VectorDemo();
	//SetDemo();
//	MapDemo();
	vector<int> nums={1,2,3,4};
	int sum=0;
//	for(int &item:nums){
//		cout<<item<<"  ";
//		sum+=item;
//		item=sum;
//		cout<<item<<endl;
//	}
	for(auto it=nums.begin();it!=nums.end();it++){
		sum+=(*it);
		*it=sum;
		cout<<*it<<endl;
	}
	return 0;
}
