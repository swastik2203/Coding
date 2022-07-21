//Tree cpp program
#include <iostream>
using namespace std;

#include "Queuecpp.h"

template <class T>
class Tree {
    private:
        Node<T> * root;

    public:
        Tree(){root = NULL;}
        void CreateTree();

        void Preorder(){Preorder(root);}    //Function overloading so that we can make root private 
        void Preorder(Node<T> *p);             //and make recursive call

        void Inorder(){Inorder(root);}
        void Inorder(Node<T> *p);

        void Postorder(){Postorder(root);}
        void Postorder(Node<T> *p);
};

template <class T>
void Tree<T>::CreateTree()
{
    Node<T> *p,*t;
    Queue<char> q(100);     //same variable as tree object is given

    root = new Node<T>;
    T x;
    cout<<"enter the root data: ";       //FORMATION OF ROOT NODE 1ST
    cin>>x;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (! (q.isEmpty()) ) 
    {
        p = q.dequeue();

        cout<<"enter the left child of "<<p->data<<" ";
        cin>>x;
        if (x != '.')
        {
            t = new Node<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout<<"enter the right child of "<<p->data<<" ";
        cin>>x;
        if (x != '.')
        {
            t = new Node<T>;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
        
    }
}

template <class T>
void Tree<T>::Preorder(Node<T> *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

template <class T>
void Tree<T>::Inorder(Node<T> *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}

template <class T>
void Tree<T>::Postorder(Node<T> *p)
{
    if(p)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

int main()
{
    Tree<char> t;

    t.CreateTree();

    cout<<"Preorder :  ";
    t.Preorder();              //no parameter passed due to function overloading
    cout<<endl;

    cout<<"Inorder :  ";
    t.Inorder();
    cout<<endl;

    cout<<"Postorder :  ";
    t.Postorder();
    cout<<endl;

}

