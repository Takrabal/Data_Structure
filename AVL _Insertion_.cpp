#include<iostream>
#include<string>

using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class node
{
    public:
        int info;
        node *left;
        node *right;
        int height;
        
    node(int val)
    {
        info = val;
        left = NULL;
        right = NULL;
        height = 0;
    }
};

int height(node *N)
{
    if (N == NULL)
        return -1;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;
 
    // Return new root
    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    // Update heights
    x->height = max(height(x->left),   
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;
 
    // Return new root
    return y;
}

void deleteTree(node* leaf)
{
    if (leaf != NULL)
    {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}

int getBalance(node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node* insert(node* n, int key)
{
    /* 1. Perform the normal BST insertion */
    if (n == NULL)
        return(new node(key));
 
    if (key < n->info)
        n->left = insert(n->left, key);
    else if (key > n->info)
        n->right = insert(n->right, key);
    else // Equal keys are not allowed in BST
        return n;
 
    /* 2. Update height of this ancestor node */
    n->height = 1 + max(height(n->left),
                        height(n->right));
 
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(n);
 
    // If this node becomes unbalanced, then
    // there are 4 cases
 
    // Left Left Case
    if (balance > 1 && key < n->left->info)
        return rightRotate(n);
 
    // Right Right Case
    if (balance < -1 && key > n->right->info)
        return leftRotate(n);
 
    // Left Right Case
    if (balance > 1 && key > n->left->info)
    {
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }
 
    // Right Left Case
    if (balance < -1 && key < n->right->info)
    {
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
 
    /* return the (unchanged) node pointer */
    return n;
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

void preOrder(node *n)
{
    if(n == NULL)
        return;
    
    cout<<n->info<<"\t";
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node *n)
{
    if(n == NULL)
        return;

    inOrder(n->left);
    cout<<n->info<<"\t";
    inOrder(n->right);
}

void postOrder(node *n)
{
    if(n == NULL)
        return;
    
    postOrder(n->left);
    postOrder(n->right);
    cout<<n->info<<"\t";
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

int main(int argc, const char** argv) {
    node* root = NULL;
    // Tree 1
    // root = insert(root, 1);
    // root = insert(root, 2);
    // root = insert(root, 3);
    // root = insert(root, 4);
    // root = insert(root, 5);
    // root = insert(root, 6);
    // root = insert(root, 7);
    // root = insert(root, 16);
    // root = insert(root, 15);

    // Tree 2
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 14);
    root = insert(root, 19);
    root = insert(root, 15);
    printTree(root, NULL, false);
    return 0;
}