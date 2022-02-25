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

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
node * minValueNode(node* n)
{
    node* current = n;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
node* deleteNode(node* root, int key)
{
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
    // If the key to be deleted is smaller
    // than the root's key, then it lies
    // in left subtree
    if ( key < root->info )
        root->left = deleteNode(root->left, key);
 
    // If the key to be deleted is greater
    // than the root's key, then it lies
    // in right subtree
    else if( key > root->info )
        root->right = deleteNode(root->right, key);
 
    // if key is same as root's key, then
    // This is the node to be deleted
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) ||
            (root->right == NULL) )
        {
            node *temp = root->left ?
                         root->left :
                         root->right;
 
            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of
                           // the non-empty child
            delete temp;
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's
            // data to this node
            root->info = temp->info;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right,
                                     temp->info);
        }
    }
 
    // If the tree had only one node
    // then return
    if (root == NULL)
        return root;
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),
                           height(root->right));
 
    // STEP 3: GET THE BALANCE FACTOR OF
    // THIS NODE (to check whether this
    // node became unbalanced)
    int balance = getBalance(root);
 
    // If this node becomes unbalanced,
    // then there are 4 cases
 
    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
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
    // root = insert(root, 14);
    // root = insert(root, 11);
    // root = insert(root, 19);
    // root = insert(root, 7);
    // root = insert(root, 12);
    // root = insert(root, 17);
    // root = insert(root, 53);
    // root = insert(root, 4);
    // root = insert(root, 8);
    // root = insert(root, 13);
    // root = insert(root, 16);
    // root = insert(root, 20);
    // root = insert(root, 60);
    // printTree(root, NULL, false);
    // root = deleteNode(root, 8);
    // cout << "After deleting 8 ..." << endl;
    // printTree(root, NULL, false);
    // root = deleteNode(root, 7);
    // cout << "After deleting 7 ..." << endl;
    // printTree(root, NULL, false);
    // root = deleteNode(root, 11);
    // cout << "After deleting 11 ..." << endl;
    // printTree(root, NULL, false);
    // root = deleteNode(root, 14);
    // cout << "After deleting 14 ..." << endl;
    // printTree(root, NULL, false);
    // root = deleteNode(root, 17);
    // cout << "After deleting 17 ..." << endl;
    // printTree(root, NULL, false);

    // Tree 2
    root = insert(root, 14);
    root = insert(root, 11);
    root = insert(root, 19);
    root = insert(root, 12);
    root = insert(root, 17);
    root = insert(root, 53);
    root = insert(root, 16);
    root = insert(root, 18);
    printTree(root, NULL, false);
    root = deleteNode(root, 12);
    cout << "After deleting 12 ..." << endl;
    printTree(root, NULL, false);
    
    return 0;
}