#include <bits/stdc++.h>
using namespace std;

// Job structure
struct Job{
	char id;
	int dead;
	int profit;
};

// function for getting max profit
bool comparison(Job a,Job b){
	return (a.profit > b.profit);
}

//Start of function
void printJobScheduling(Job arr[],int n){
	// sorting on basis of profit
	sort(arr,arr+n,comparison);
	
	int result[n];
	bool slot[n];
	
	//getting jobs
	for(int i=0;i<n;i++){
		//finding slot to schedule job
		for(int j=min(n,arr[i].dead)-1;j>=0;j--){
			// got free slot
			if(slot[j]==false){
				result[j]=i;
				slot[j]=true;
				break;
			}
		}
	}
	
	//printing all the job id's
	for(int i=0;i<n;i++){
		if(slot[i]) cout<<arr[result[i]].id<<" ";
	}
}
int main(){
	Job arr[]={{'a',2,100},{'b',1,19},{'c',2,27},{'d',1,25},{'e',3,15}};
	int n=sizeof(arr)/sizeof(arr[0]);
	printJobScheduling(arr,n);
	return 0;
}
