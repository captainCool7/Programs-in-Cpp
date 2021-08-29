#include<iostream>
using namespace std;

class Node{
	public:
		Node* lchild;
		int data;
		Node* rchild;
};

class BST{
	private:
		Node* root;
	public:
		BST(){ root = nullptr;}
		Node* getRoot(){ return root;}
		void iInsert(int key);
		void Inorder(Node* p);
//		Node* iSearch(int key);
//		Node* rInsert(Node* p,int key);
//		Node* rSearch(Node* p,int key);
//		Node* Delete(Node* p,int key);
		int Height(Node* p);
//		Node* InPre(Node* p);
//		Node* InSucc(Node* p);
};

int BST::Height(struct Node *p){
	int x,y;
	if(p==nullptr) return 0;
	x=Height(p->lchild);
	y=Height(p->rchild);
	return x>y?x+1:y+1;
}

void BST::iInsert(int key){
	Node* t = root;
	Node* p;
	Node* r;
	if(root==nullptr){
		p = new Node;
		p->data=key;
		p->lchild=nullptr;
		p->rchild=nullptr;
		root=p;
		return;
	}
	while(t !=nullptr){
		r=t;
		if(key<t->data) t=t->lchild;
		else if(key>t->data) t=t->rchild;
		else return;
	}
	p=new Node;
	p->data = key;
	p->lchild=nullptr;
	p->rchild=nullptr;
	if(key<r->data) r->lchild=p;
	else r->rchild=p;
}

void BST::Inorder(Node *p){
	if(p){
		Inorder(p->lchild);
		cout<<p->data;
		Inorder(p->rchild);
	}
}

int main(){
	BST bst;
	bst.iInsert(20);
	bst.iInsert(10);
	bst.iInsert(30);
	bst.iInsert(5);
	bst.iInsert(15);
	bst.iInsert(25);	
	bst.iInsert(35);
	bst.iInsert(45);
	bst.Inorder(bst.getRoot());
	return 0;
}
