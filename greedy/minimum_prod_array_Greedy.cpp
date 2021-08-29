#include<bits/stdc++.h>
using namespace std;
int main(){
	int count_zero=0,count_neg=0,min_pos=INT_MIN,max_neg=INT_MAX,product=1;
	//
	int a[] = { 1, 0,2,4 };
	int n = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++){
		
		//counting zero
		if(a[i]==0) {
			count_zero++;
			continue;	
		}
		
		//counting negitive
		if(a[i]<0){
			count_neg++;
			max_neg=max(max_neg,a[i]);
		} 
		// finding minimum positive
		if(a[i]>0){
			min_pos=min(min_pos,a[i]);
		} 
		// product calculation
		product*=a[i];
	}
	
	if(count_zero==n or count_neg==0 and count_zero>0){
		cout<< 0;
	} 
	// if there is no negative number
	if(count_neg==0){
		cout<< min_pos;
	} 
	// removing maximum negative number
	if(count_neg%2==0 and count_neg!=0){
		product/=max_neg;
	} 
	cout<<product<<" ";
//	cout<<product;
	return 0;
}
