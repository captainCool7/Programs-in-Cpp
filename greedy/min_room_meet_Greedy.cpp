#include<bits/stdc++.h>
using namespace std;

int get_min_room(vector<vector<int>> sche){
	//making 2 array for start and end time
	int start[sche.size()];
	int end[sche.size()];
	int i=0,count=1;
	
	//storing values into arrays
	for(auto v:sche){
		start[i]=v[0];
		end[i]=v[1];
		i++;
	}
	
	//sorting 2 arrays
	sort(start,start+i);
	sort(end,end+i);
	int s=1,p=0;
	
	//if another meeting is getting stared before older assign new room
	for(;s<i;s++){
		if(start[s]<end[p]){
		count++;
		p++;
		}	
	}
	return count;	
}
int main(){
	//vector of schedule
	vector<vector<int>> sche{{0,5},{1,2},{6,10}};
	cout<<get_min_room(sche);
	return 0;
}
