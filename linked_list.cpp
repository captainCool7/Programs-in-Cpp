#include<iostream>
using namespace std;

struct node{
	int val;
	struct node *next;
};
struct node *addatbeg(struct node *start,int data){
	struct node *tmp;
	tmp = (struct node *)malloc(sizeof(struct node));
	tmp->val = data;
	tmp->next = start;
	start=tmp;
	return start;
}
struct node *addatend(struct node *start,int data){
	struct node *p,*temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->val = data;
	p=start;
	while(p->next!=NULL) p =p->next;
	p->next=temp;
	temp->next = NULL;
	return start;
}
struct node *create_list(struct node *start){
	int i,n,data;
	cout<<"Enter the number of nodes: ";
	cin>>n;
	start=NULL;
	if(n==0) return start;
	cout<<"Enter the element to be inserted: ";
	cin>>data;
	start = addatbeg(start,data);
	for(i=2;i<=n;i++){
		cout<<"Enter the element to be inserted: ";
		cin>>data;
		start=addatend(start,data);
	}
	return start;
}
void move(struct node *start){
	struct node *p = start;
	while(p!=NULL){
		cout<<p->val<<" ";
		p=p->next;
	}
}
int main(){
	struct node *start=NULL;
	start = create_list(start);
	move(start);
	return 0;
}
