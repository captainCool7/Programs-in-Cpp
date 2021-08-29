#include<iostream>
using namespace std;
class Stack{
	public:
		int size,rear;
		int *Q;
		Stack(int s);
};
Stack::Stack(int s){
	size=s;
	rear=-1;
	Q = new int[s];
}
void enqueue(Stack *s,int n){
	if(s->rear!=s->size){
		s->rear+=1;
		s->Q[s->rear]=n;
		cout<<"Pushed at "<<s->rear<<" value is "<<s->Q[s->rear]<<endl;
	}
}
int dequeue(Stack *s1,Stack *s2){
	int x=-1;
	if(s2->rear==-1){
		while(s1->rear>=0){
			s2->rear+=1;
			s2->Q[s2->rear]=s1->Q[s1->rear];
			s1->rear-=1;
			cout<<"Transferred : "<<s2->Q[s2->rear]<<endl;
		}
	}
	x = s2->Q[s2->rear];
	s2->rear-=1;
	return x;
}
int main(){
	Stack s1 = Stack(4);
	Stack s2 = Stack(4);
	enqueue(&s1,0);
	enqueue(&s1,1);
	enqueue(&s1,2);
	enqueue(&s1,3);
	cout<<dequeue(&s1,&s2);
	cout<<dequeue(&s1,&s2);
	cout<<dequeue(&s1,&s2);
	cout<<dequeue(&s1,&s2);
	enqueue(&s1,0);
	enqueue(&s1,1);
	cout<<dequeue(&s1,&s2);
	return 0;
}
