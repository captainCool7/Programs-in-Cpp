#include<iostream>
using namespace std;
void swap(int *a,int *b){
	*a = *a+*b;
	*b=*a-*b;
	*a = *a-*b;
}
void printArr(int *a,int n){
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
}
void sort2d(int *arr,int i,int j){
	while(i<=j){
		if(arr[i]<0){
			i++;
		}else if(arr[j]>0){
			j--;
		}else if(arr[i]>0&&arr[j]<0){
			swap(&arr[i++],&arr[j++]);
		}
	}
}

int main(){
	int arr[] = {-1,2,-3,4,5,6,-7,8,9};
	int n = sizeof(arr)/sizeof(int);
	sort2d(arr,0,n-1);
	printArr(arr,n);
	return 0;
}
