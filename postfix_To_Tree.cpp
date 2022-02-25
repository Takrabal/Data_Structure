#include <iostream>
#include<bits/stdc++.h> 
using namespace std; 
  
struct node 
{ 
    char value; 
    node* left, *right; 
}; 

node* create_Node(char v) 
{ 
    node *curr = new node; 
    curr->left = curr->right = NULL; 
    curr->value = v; 
    return curr; 
}; 
  
bool Operator(char ch) 
{ 
    if (ch == '^' || ch == '+' || ch == '/' || ch == '*' || ch == '-') 
        return true; 
    return false; 
} 
   
node* create_Tree(char p_fix[]) 
{ 
    stack<node *> stack; 
    node *T, *T1, *T2; 
  
    for (int i=0; i<strlen(p_fix); i++) 
    { 
        
        if (!Operator(p_fix[i])) 
        { 
            T = create_Node(p_fix[i]); 
            stack.push(T); 
        } 
        else 
        { 
            T = create_Node(p_fix[i]); 
  
            
            T1 = stack.top(); 
            stack.pop();      
            T2 = stack.top(); 
            stack.pop(); 
  
            
            T->right = T1; 
            T->left = T2; 
  
            
            stack.push(T); 
        } 
    } 
  
    T = stack.top(); 
    stack.pop(); 
  
    return T; 
} 

void in_order(node *n) 
{ 
    if(n!=NULL) 
    { 
        in_order(n->left); 
        cout<<n->value; 
        in_order(n->right); 
    } 
}
  

int main() 
{ 
    char pstfix_exp[] = "ab+cde+**"; 
    node* root = create_Tree(pstfix_exp); 
    cout<<" Expression is "; 
    in_order(root);
    cout<<'\n';

    return 0; 
} 