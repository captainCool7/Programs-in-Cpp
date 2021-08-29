#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class BST
{
public:
    Node *root;
    BST() { root = nullptr; }
    void iInsert(int key);
    void Inorder(Node *p);
};

void BST::iInsert(int key)
{
    Node *t = root;
    Node *p;
    Node *r;
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
    while (t != nullptr)
    {
        r = t;
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

// Return the child with maximum numbers of childrens under that.
int findDepth(Node *root)
{
    if (root == NULL)
        return 0;
    int x = findDepth(root->lchild);
    int y = findDepth(root->rchild);
    return x > y ? (x + 1) : (y + 1);
}
void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data;
        Inorder(p->rchild);
    }
}
int main()
{
    BST bst;
    bst.iInsert(20);
    bst.iInsert(10);
    bst.iInsert(30);
    bst.iInsert(5);
    bst.iInsert(15);
    bst.iInsert(25);
    bst.iInsert(35);
    // bst.iInsert(45);
    // bst.Inorder(bst.root);
    cout << findDepth(bst.root);
    return 0;
}