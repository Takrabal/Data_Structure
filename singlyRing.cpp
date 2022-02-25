#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class singlyRing{
    private:
        int length;
        node *curr, *temp, *head;
    
    public:
        singlyRing(){
            length=0;
            curr=temp=head=NULL;
        }

    void Insert (int val, int pos){
        curr=head;
        if (head==NULL){
            node *n=new node;
            n->data=val;
            head = n;
            head->next=head;
        }
        else if (pos==1)
        {   
            node *n=new node;
            n->data=val;
            n->next=curr;
            
            while(curr!=head)
            {
              curr=curr->next;
            }
            curr->next=n;
            head=n;
        }
        else
        {
            for (int i=2; i<=pos; i++)
            {   
                if (pos==i)
                {
                    node *n=new node;
                    n->data=val;
                    n->next=curr->next;
                    curr->next=n;
                }
                curr=curr->next;
            }
            
        }

      length++;   
    }

    void insertEnd(int val)
    {
        curr=head;
        if (head==NULL)
        {
            node *n=new node;
            n->data=val;
            head=n;
            head->next=head;
            
            
        }
        else
        {   node *n=new node;
            n->data=val;
            n->next=head;
        
            while (curr->next!=head)
            {
                curr=curr->next;
            }
            curr->next=n;
        }
        
        
    }
    
    void Remove(int pos)
    {   curr=head;
        if (head==NULL)
        {
            cout<<"list is empty cant delete anything"<<endl;
        }

        else if (pos==1)
        {   
            //head = head->next;
            temp=head;
            while(curr->next!=head)
            {
                curr=curr->next;
            }
            head=head->next;
            curr->next=head;
            delete temp;
            
        }
        else
        {
            for(int i=1; i<pos; i++ )
            {
                temp=curr;
                curr=curr->next;
            } 
            temp->next=curr->next;
            delete curr;
        }
        //length--;
    }

    void print()
    {   curr=head;
        if(head==NULL)
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            
            do {
                cout<<curr->data<<endl;
                curr=curr->next; 
            }
            while (curr->next!=head);
               cout<<curr->data<<endl;
        }
        
    }
};




int main(){
    singlyRing R;
    R.Insert(2,1);
    R.Insert(6,1);
    R.Insert(4,2);
    R.Insert(3,3);
    //R.Insert(3,1);
    
    //R.Insert(7,3);
    //R.Insert(3,4);
    //R.Insert(3,1);

    //R.insertEnd(2);
    //R.insertEnd(4);
    //R.insertEnd(7);

    //R.Remove(1);
    R.Remove(2);
    R.Remove(3);
    
    R.print();
    //R.Insert(3,4);
    //R.Remove(1);
    //R.Remove(2);

    //R.print();
    
    
    
    
    
    
    return 0;
}