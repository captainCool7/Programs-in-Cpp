#include<iostream>
using namespace std;

struct Node{
	struct Node *lchild;
	int data;
	struct Node *rchild;
}*root=NULL;


// Insert Iterative
void insert(int key){
	struct Node *t=root;
	struct Node *r,*p;
	if(root==NULL){
		p =new Node();
		p->data=key;
		p->lchild=p->rchild=NULL;
		root=p;
		return;
	}
	while(t!=NULL){
		r=t;
		if(key<t->data) t=t->lchild;
		else if(key>t->data) t=t->rchild;
		else return;
	}
	p=new Node();
	p->data=key;
	p->lchild=p->rchild=NULL;
	
	if(key<r->data) r->lchild=p;
	else r->rchild=p;
}

// Insert Recursive
struct Node *RInsert(struct Node *p,int key){
	if(p==NULL){
		struct Node *t = new Node();
		t->data = key;
		t->lchild=t->rchild=NULL;
		return t;
	}
	if(key<p->data) p->lchild=RInsert(p->lchild,key);
	else if(key>p->data) p->rchild=RInsert(p->rchild,key);
	
	return p;
}

//Traversing
void Inorder(struct Node *p){
	if(p){
		Inorder(p->lchild);
		cout<<p->data;
		Inorder(p->rchild);
	}
}

int Height(struct Node *p){
	int x,y;
	if(p==NULL) return 0;
	x=Height(p->lchild);
	y=Height(p->rchild);
	return x>y?x+1:y+1;
}

struct Node* Pre(struct Node *p){
	while(p and p->rchild!=NULL) p=p->rchild;
	return p;
}

struct Node* Succ(struct Node *p){
	while(p and p->lchild!=NULL) p=p->lchild;
	return p;
}
// Deletion
struct Node* RDelete(struct Node *p,int key){
	struct Node *q;
	if(p==NULL) return NULL;
	if(p->lchild==NULL and p->rchild==NULL){
		if(p==root) root=NULL;
		delete(p);
		return NULL;
	}
	
	if(key<p->data) p->lchild=RDelete(p->lchild,key);
	else if(key>p->data) p->rchild=RDelete(p->rchild,key);
	else{
		if(Height(p->lchild)>Height(p->rchild)){
			q=Pre(p->lchild);
			p->data=q->data;
			p->lchild=RDelete(p->lchild,q->data);
		}else{
			q=Succ(p->rchild);
			p->data=q->data;
			p->rchild=RDelete(p->rchild,q->data);
		}
	}
	return p;
}
void Postorder(struct Node *p){
	if(p){
		Postorder(p->lchild);
		Postorder(p->rchild);
		cout<<p->data;
	}
}

//Iterative search
struct Node* search(int key){
	struct Node* t=root;
	while(t!=NULL){
		if(t->data == key) return t;
		else if(key<t->data) t = t->lchild; 
		else t = t->rchild;
	}
	return NULL;
}

//recursive search
struct Node* rsearch(struct Node* p,int key){
	if(p==nullptr) return NULL;
	if(p->data == key) return p;
	else if(key<p->data) rsearch(p->lchild,key);
	else rsearch(p->rchild,key);
}
int main(){
	struct Node *temp;
//	insert(10);
//	insert(12);
//	insert(17);
//	insert(15);
//	insert(2);
//	insert(6);
//	insert(4);
	root=RInsert(root,10);
	RInsert(root,15);
	RInsert(root,17);
	RInsert(root,12);
	RInsert(root,2);
	RInsert(root,6);
	RInsert(root,4);
	RDelete(root,10);
	Inorder(root);
	temp=rsearch(root,10);
	if(temp!=NULL)
		cout<<endl<<temp->data;
	else
		cout<<endl<<"Element not found is BST";
	return 0;
}
