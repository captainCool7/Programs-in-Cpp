#include<bits/stdc++.h>
//#include<vector>
using namespace std;
int binaryMedian(vector<vector<int>> &m,int r,int c){
	int min = INT_MAX,max=INT_MIN;
	for(int i=0;i<r;i++){
		min = m[i][0]<min?m[i][0]:min;
		max = m[i][c-1]>max?m[i][c-1]:max;
	}
	int desired = (r*c+1)/2;
	
	while(min<max){
		int mid = min+(max-min)/2;
		cout<<"mid is: "<<mid<<endl;
		int place =0;
		for(int i=0;i<r;i++){
			place+=upper_bound(m[i].begin(),m[i].end(),mid)-m[i].begin();
		}
		if(place<desired) min =mid+1;
		else max = mid;
		}
	return min;
	}

int main(){
	int r=3,c=3;
	vector<vector<int>> m({ {1,3,5}, {2,6,9}, {3,6,9} });
	cout << "Median is "<<binaryMedian(m,r,c)<<endl;
	return 0;
}
