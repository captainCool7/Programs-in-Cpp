#include<stdio.h>
int main(){
	int max=0;
	int a=0;
	int b=0;
	int t=0;
	int arr[]={140,89,90,112,88};
	int arr1[]={82,134,110,106,90};
	for(int i=0;i<5;i++){
		if(arr[i]>arr1[i]){
			t=arr[i]-arr1[i];
			a+=t;
		}else{
			t=arr1[i]-arr[i];
			b+=t;
		}
		printf("%d %d\n",a,b);
		if(max<t)
			max=t;			
		}
		t = (a>b)?1:2;
		printf("%d %d",t,max);
	return 0;
}
