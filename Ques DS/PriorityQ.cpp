#include<iostream>
using namespace std;
class PQ{
	public:
		int m,mlast,n,nlast,o,olast;
		char *a,*b,*c;
		PQ();
		void setPriority(char x,int num);
		void enqueue(char *arr,char ch,int *num);
		char dequeue(int front,int rear);
};
PQ::PQ(){
	a= new char[8];
	b= new char[8];
	c= new char[8];
	int m=mlast=n=nlast=o=olast=0;
}
void PQ::enqueue(char *arr,char ch,int *num){
	if(*num!=8){
		arr[*num]=ch;
		*num+=1;
	}else{
		cout<<"Queue is full\n";
	}
}
void PQ::setPriority(char ch,int num){
	
}
int main(){
	PQ obj= PQ();
//	int x=0
	obj.enqueue(obj.a,'z',&obj.mlast);
	cout<<obj.a[0]<<" "<<obj.mlast;
	return 0;
}
