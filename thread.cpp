#include <iostream>
using namespace std;


struct node {
    int info;
    node *right;
    node *left;
    int leftbit;
    int rightbit;
};

class thread
{
    public:
        node *root;
        node *dummy;


        thread () 
        {
            root=NULL;
            dummy=new node;
            dummy->left=dummy;
            dummy->right=dummy;
            dummy->leftbit=0;
            dummy->rightbit=1;
        }

    void insert(int key, node *temp)
    {
        if (root==NULL)
        {
            /* code */
        
        temp=new node;
        temp->info=key;
        temp->left=dummy;
        temp->right=dummy;
        dummy->leftbit=1;
        temp->rightbit=0;
        temp->leftbit=0;
        root=temp;
        return;
        }

        if(key==temp->info)
        {
            cout<<"no duplicate allowed"<<endl;
            return;
        }

        if(key>temp->info)
        {
            if(temp->rightbit==0)
            {
                node *n=new node;
                n->info=key;
                n->right=temp->right;
                n->rightbit=temp->rightbit;
                temp->right=n;
                temp->rightbit=1;
                n->left= temp;
                n->leftbit=0;
                return;

            }

            else
            {
                insert(key, temp->right);
            }
            
        }

        if (key< temp->info)
        {
            if(temp->leftbit==0)
            {
                node *n=new node;
                n->info=key;
                n->left= temp->left;
                n->leftbit=temp->leftbit;
                temp->left=n;
                temp->leftbit=1;
                n->right= temp;
                n->rightbit=0;
                return;
            }

            else
            {
                insert(key, temp->left);
            }
            
        }

    }

    void traverse(node *temp)
    {
        if(temp->leftbit ==1)
        {
            traverse(temp->left);
        }

        cout<<temp->info<<endl;

        if(temp->rightbit==1)
        {
            traverse(temp->right);
        }
    }

    void deletion(int key, node *temp)
    {
        if (root == NULL)
        {
            cout<<"tree is empty "<<endl;
            return;
        }

        if(temp->left->info==key)
        {
            delete_node(temp->left,temp);
            return;
        }

        if ((temp!=dummy) &&(temp->right->info==key))
        {
            delete_node(temp->right, temp);
            return;
        }
        
        if (temp==dummy)
        {
            deletion(key, temp->right);
            return;
        }

        if((key > temp->info) && (temp->rightbit==1))
        {
            deletion(key, temp->right);
        }

        if((key< temp->info) && (temp->leftbit==1))
        {
            deletion(key, temp->left);
        } 

        else
        {   
            cout<<"value not exist "<<endl;
            return;
        }    
    }

    void delete_node(node *temp, node *parent)
    {
        if (temp->leftbit==1 && temp->rightbit==1)
        {
            node *succ_parent=temp;
            node *succ=find_succ(temp->right, succ_parent);
            temp->info= succ->info;
            delete_node(succ, succ_parent);
            return;
        }

        if (temp->leftbit==1 && temp->rightbit==0)
        {
            if(temp->info < parent->info)
            {
                parent->left = temp->left;
                parent->leftbit = temp->rightbit;
            }

            else
            {
                parent->right = temp->left;
                parent->rightbit = temp->rightbit;
            }

            node *temp2=temp->left;
            while (temp2->rightbit!=0)
            {
                temp2=temp2->right;
            }
            
            temp2->right = temp->right;

            delete temp;
            return;
        }

        //third case
        if (temp->rightbit==1 && temp->leftbit==0)
        {
            if(temp->info < parent->info)
            {
                parent->right=temp->right;
                parent->rightbit = temp->leftbit;
            }

            else
            {
                parent->left = temp->right;
                parent->leftbit = temp->leftbit;
            }

            node *temp2=temp->right;
            while (temp2->leftbit!=0)
            {
                temp2=temp2->left;
            }
            
            temp2->left = temp->left;
            delete temp;
            return;

        }
        

        if (temp->leftbit==0 && temp->rightbit==0)
        {
            if (parent->left==temp)
            {
                parent->left=temp->left;
                parent->leftbit=0;
            }

            if (parent->right==temp && parent!=dummy) 
            {
                /* code */
                parent->right=temp->right;
                parent->rightbit=0;
            }
            
            if (temp==root)
            {
                root =NULL;
                dummy->left=dummy;
                dummy->leftbit=0;
            }
            
            delete temp;
            
        }
        
    }

    node * find_succ(node *temp, node *&parent )
    {
        if (temp->leftbit==0)
        {
            return temp;
        }
        parent = temp;

        return find_succ(temp->left, parent);
        
    }

};


int main()
{   thread t;
    t.insert(6, t.root);
    t.insert(3, t.root);
    t.insert(8, t.root);
    t.insert(1, t.root);
    t.insert(5, t.root);
    t.insert(4, t.root);
    t.insert(8, t.root);
    t.insert(7, t.root);
    t.insert(11, t.root);
    t.insert(9, t.root);
    t.insert(13, t.root);
    t.insert(10, t.root);
    t.deletion(3, t.root);
    t.deletion(4, t.root);
    t.deletion(10, t.root);
    t.deletion(1, t.root);
    t.traverse(t.root);

    return 0;
}