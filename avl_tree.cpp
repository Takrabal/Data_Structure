#include <iostream>
using namespace std;
#include<math.h>


struct node{
    
        node *left, *right;
        int info, height;

};

class Avl 
{
    public:
        node * root;


    Avl()
    {
        root = NULL;
    }
    
    int _height (node * h)
    {
        if (h == NULL)
        {
            return -1;
        }
        else
        {
            int l=_height(h->left);
            int r=_height(h->right);
            if(l>r)
            return (l+1);
            else
                (r+1);
        }
    }


    int getBalance(node *n)
    {
        if (n == NULL)
        {
            return 0;
        }

        return _height(n->left) - _height(n->right);
                
    }

    node *rightRotate(node *k)
    {
        node *x=k->left;
        node *T2=x->right;

        x->right = k;
        k->left = T2;



        return x;
    }

    node *leftRotate(node *k)
    {
        node *x=k->right;
        node *T2=x->left;

        x->left = k;
        k->right = T2;


        return x;

    }


    node * insert(node *&n, int key)
    {
        if (n==NULL)
        {   
            n=new node;
            n->info=key;
            n->left=NULL;
            n->right=NULL;
            return n;
        }
        
        if (key<n->info)
        {
            n->left=insert(n->left, key);
            return n;
        }
        
        if (key>n->info)
        {
            n->right=insert(n->right, key);
            return n;
        }
        
        if(key==n->info)
        {
            return n;
        }

        n->height = 1 + max(_height(n->left),
                        _height(n->right));

        int balance = getBalance(n);
            //left left Case
        if (balance > 1 && key < n->left->info)
        {
            return rightRotate(n);
        }
            //left right case
        if (balance > 1 && key > n->left->info)
        {
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }
            //right right Case
        if (balance < -1 && key > n->right->info)
        {
            return leftRotate(n);
        }
            //right left case
        if (balance < -1 && key < n->right->info)
        {
            n->right =  rightRotate(n->right);
            return leftRotate(n);
        }
        return n;
    }

    void inOrder(node *n)
    {
        if(n == NULL)
            return;

        inOrder(n->left);
        cout<<n->info<<"\t";
        inOrder(n->right);
    }
};

int main()
{ 
    Avl t;
    
     t.insert(t.root, 7);
     t.insert(t.root, 5);
     t.insert(t.root, 16);
     t.insert(t.root, 14);
     t.insert(t.root, 19);
     t.insert(t.root, 15);
     t.insert(t.root,6);
     t.insert(t.root,9);
    

    t.inOrder(t.root);
    int b=t.getBalance(t.root);
    cout<<b<<endl;
    
    return 0;
}