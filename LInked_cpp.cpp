#include<iostream>
using namespace std;

struct node{
	int val;
	node *next;
};

struct node *addAtStart(struct node *start,int data){
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->val=data;
	temp->next=start;
	start =temp;
	return start;
}
struct node *addAtEnd(struct node *start,int data){
	struct node *p,*temp;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->val=data;
	temp->next = NULL;
	p=start;
	while(p->next!=NULL) p=p->next;
	p->next = temp;
	return start;
}
struct node *create_list(struct node *start){
		int size,num;
		cout<<"Enter the number of nodes: ";
		cin>>size;
		cout<<"Enter the node value: ";
		cin>>num;
		start = addAtStart(start,num);
		for(int i=2;i<=size;i++){
			cout<<"Enter the node value: ";
			cin>>num;
			start = addAtEnd(start,num);
		}
		return start;
	}
	
void move(struct node *start){
	struct node *p = start;
	while(p!=NULL){
		cout<<p->val<<" ";
		p = p->next;
	}
}
int main(){
	struct node *start=NULL;
	start = create_list(start);
	move(start);
	return 0;
}
