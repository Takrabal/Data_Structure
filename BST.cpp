#include <iostream>
using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
   
};

class BST
{
 public:
    node *root;

    BST() 
    {
        root = NULL;
    }

    void insert(int key, node *& temp)
    {
        if (temp==NULL)
        {
            temp = new node;
            temp->value = key;
            temp->left = NULL;
            temp->right = NULL;
            
            return;
        }

        if (key==temp->value)
        {
            cout<<"no duplication is allowed "<<endl;
            return;
        }

        if (key < temp->value)
        {
            insert(key,temp->left);
            return;
        }
        
        if (key > temp->value)
        {
            insert(key,temp->right);
            return;
        }
         
    }

    node * search ( int key, node *root)
    {
        if (root==NULL)
        {
            cout << "empty"<<endl;
            
        }

        if (key==root->value)
        {   
            return root;
            
        }

        if (key < root->value)
        { 
              return search(key,root->left);
        }
        if (key > root->value)
        {
            return search(key,root->right);
        }

    return root;
        
    }

    void TraverseInorder(node *n)
    {
        if (n==NULL)
        {
            return;
        }

        TraverseInorder(n->left);
        cout<<n->value<<endl;
        TraverseInorder(n->right);
        
    }

    void TraversePreorder(node *n)
    {
        if (n==NULL) 
        {
            return;
        }
        
        cout<<n->value<<endl;
        TraversePreorder(n->left);
        TraversePreorder(n->right);
    }

    void TraversePostorder(node *n)
    {
        if (n==NULL) 
        {
            return;
        }

        TraversePostorder(n->left);
        TraversePostorder(n->right);
        cout<<n->value<<endl;
    }
    
    node *MinValue(node *n2)
    {   
        if (n2==NULL) 
        {
            return 0;
        }
        if (n2->left==NULL)
        {
            return n2;
        }
        
        MinValue(n2->left);
        
    }


    node* Successor(node* root, node* succ, int key)
    {
    
     if (root == NULL)
      {
        return succ;
      }
   
     if (root->value == key)
      {
        if (root->right != NULL) 
        {
            return MinValue(root->right);
        }
      }
    
     else if (key < root->value)
     {
        
        succ = root;
        return Successor(root->left, succ, key);
      }
 
     else 
     {
        return Successor(root->right, succ, key);
     }
     
     return succ;
    }
   
    
    node* deleteN(node* root, int k)
    {
       if (root == NULL)
         return root;
 
       if ( k < root->value ) 
       {
          root->left = deleteN(root->left, k);
          return root;
       }
       else if ( k > root->value) 
       {
           root->right = deleteN(root->right, k);
           return root;
       }
 
       if (root->left == NULL) 
       {
           node* temp = root->right;
           delete root;
           return temp;
       }
       else if (root->right == NULL) 
       {
          node* temp = root->left;
          delete root;
          return temp;
       }
 
       else 
       {
          node* succParent = root;
           node* succ = root->right;

           while (succ->left != NULL) 
           {
              succParent = succ;
              succ = succ->left;
           }

           if (succParent != root)
             succParent->left = succ->right;
           else
            succParent->right = succ->right;
 
           root->value = succ->value;
 
           delete succ;
           return root;
        }
    }
 
    int maxDepth(node* node)  
    {  
        if (node == NULL)  
            return -1;  
        else
        {  
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);  
        int rDepth = maxDepth(node->right);  
      
        /* use the larger one */
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
         }  
    }

    int getLevel(node *ptr,int val,int level) 
    {
        if (ptr == NULL)
            return 0;
        if (ptr->value == val)
            return level;
        return getLevel(ptr->left, val, level+1) | 
            getLevel(ptr->right, val, level+1);
    }

    int getBalance(node *n)
    {
        int left=maxDepth(n->left);
        int right=maxDepth(n->right);

        return left-right;
                
    }

};

int main(){

    BST t;
    t.insert(100,t.root);
    t.insert(70,t.root);
    t.insert(200,t.root);
    t.insert(1,t.root);
    t.insert(90,t.root);
    t.insert(75,t.root);
    t.insert(300,t.root);
    t.insert(400,t.root);
    t.insert(500,t.root);

    if(t.search(70,t.root)==NULL)
    {
        cout<<"key does not exist"<<endl;
    }
    else
    {
        cout<<"key exists"<<endl;
    }
    cout<<"inorder tree traverse"<<endl;
    t.TraverseInorder(t.root);
    cout<<endl;
    cout<<"post order tree traverse"<<endl;
    t.TraversePostorder(t.root);
    cout<<endl;
    cout<<"pre order tree traverse"<<endl;
    t.TraversePreorder(t.root);

   
    cout<<endl;
    cout<<"successor value is ";
    node *s=t.Successor(t.root, NULL, 500);
     if (s!=NULL)
     {
        cout<<s->value<<endl;
     }
     else
     {
        cout<<"not found"<<endl;
     }
    
     node *s1=t.Successor(t.root, NULL, 75);
        cout<<s1->value<<endl;
     node *s2=t.Successor(t.root, NULL, 70);
        cout<<s2->value<<endl;

     node *s3=t.Successor(t.root, NULL, 400);
        cout<<s3->value<<endl;


    cout<<endl;
    t.deleteN(t.root, 75);
    cout<<"inorder traverse after deleted a node"<<endl;
    t.TraverseInorder(t.root);

    cout<<endl;
    t.deleteN(t.root, 70);
    cout<<"inorder traverse after deleted a node"<<endl;
    t.TraverseInorder(t.root);

    cout<<endl;
    t.deleteN(t.root, 200);
    cout<<"inorder traverse after deleted a node"<<endl;
    t.TraverseInorder(t.root);

    return 0;
}



 