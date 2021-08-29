#include<iostream>
#include<stdlib.h>
using namespace std;
int* sort3num(int *a,int n){
	int x,y,z;
	z=n;
	y=1;
	x=0;
	for(int i=0;i<n;i++){
		if(a[i]==2){
			arr[--z]=2;
		}else if(a[i]==0){
			arr[x]=0;
		}else if(a[i]==1){
			arr[++x]=1;
		}
		cout<<a[i]<<endl;
	}
	return arr;
}
int main(){
	int arr[] = {0,2,1,0,0,2,1,2,0,1,2};
	int n = sizeof(arr)/sizeof(int);
	int *res =sort3num(arr,n);
	for(int i=0;i<n;i++){
		cout<<res[i];
	}
	return 0;
}
