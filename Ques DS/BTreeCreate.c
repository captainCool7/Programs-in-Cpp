#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
struct Node *root=NULL;
void CreateTree(){
	struct Node *p,*temp;
	int x;
	struct Queue q;
	create(&q,100);
	printf("Enter the value of root node: \n");
	scanf("%d",&x);
	root = (struct Node*)malloc(sizeof(struct Node));
	root->data=x;
	root->lchild=root->rchild=NULL;
	enqueue(&q,root);
	while(!isEmpty(q)){
		p=dequeue(&q);
		printf("Enter the data of left child of %d: \n",p->data);
		scanf("%d",&x);
		if(x!=-1){
			temp = (struct Node *)malloc(sizeof(struct Node *));
			temp->data=x;
			temp->lchild=temp->rchild=NULL;
			p->lchild=temp;
			enqueue(&q,temp);
		}
		printf("Enter the data of right child of %d: \n",p->data);
		scanf("%d",&x);
		if(x!=-1){
			temp = (struct Node *)malloc(sizeof(struct Node *));
			temp->data=x;
			temp->lchild=temp->rchild=NULL;
			p->rchild=temp;
			enqueue(&q,temp);
		}
	}
}
void PreOrder(struct Node *p){
	if(p){
		printf("%d ",p->data);
 		PreOrder(p->lchild);
 		PreOrder(p->rchild);
	}
}
int main(){
	CreateTree();
	PreOrder(root);
	return 0;
}

