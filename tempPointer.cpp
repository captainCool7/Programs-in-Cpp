#include<iostream>
using namespace std;
int main(){
	int a[]={10,30,40};
	int b=20;
	int* p=&b;
	*(p+1)=30;
	cout<<*p<<" "<<*(p+1)<<endl;
//	*p=b;
//	cout<<*p<<" "<<p<<endl;
//	cout<<a<<" "<<b;
for(int i:a){
	cout<<i<<" ";
}
	return 0;
}
