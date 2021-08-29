#include<bits/stdc++.h>
using namespace std;

struct Item{
	int weight;
	int value;
	//storing ratio to select items on basis of ratio
	int ratio;
	int inx;
	
	//constructor for struct
	Item(int w,int val,int ids){
		weight=w;
		value=val;
		ratio=val/w;
		inx=ids;
	}
};
// compare func for sorting on ratio
bool compare(Item a,Item b){
	return (a.ratio>b.ratio);
}

//finding sum
int get_max_value(int w[],int val[],int capacity,int n){
	vector<Item> list;
	//creating struct items
	for(int i=0;i<n;i++){
		Item temp(w[i],val[i],i);
		list.push_back(temp);
	}
	
	//sorting
	sort(list.begin(),list.end(),compare);
	
	int totalValue=0;
	for(Item i:list){
		int cwt=i.weight; //current item weight 
		int cval=i.value; //current item value
		//if space left in knapsack take all the item of that type
		if(capacity-cwt>=0){
			capacity-=cwt;
			totalValue+=cval;
		}else {
			//getting fraction of remaining space
			double frac = (double)capacity/(double) cwt;
			
			//adding value accouting to
			totalValue+=(cval*frac);
			capacity=(int) (capacity-(cwt*frac));
			break;
		}
	}
	return totalValue;
}
int main(){

	int w[]={10,40,20,30};
	int val[]={60,40,100,120};
	int n = sizeof(w)/sizeof(w[1]);
	int capacity=50;
	cout<<get_max_value(w,val,capacity,n);
	return 0;
}
