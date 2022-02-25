#include <iostream>
using namespace std;

struct node{
    int data=0;
    node *next=NULL;
    node *prev=NULL;


};

class doubly{
    private:
        int len;
        node *head;
        node *curr, *temp1;

    public:
        doubly(){
        head=curr=temp1=NULL;
        len=0;}

    void insertion (int val, int pos){
        curr=head;
        if(head==NULL){
            head=new node;
            head->data=val;
            head->next=NULL;
            head->prev=NULL;
            cout<<"entered at head"<<endl;
        }

       else if(pos==1){
            node *n=new node;
            n->data=val;
            n->next=curr;
            curr->prev=n;
            head=n;
            cout<<"entered at pos 1"<<endl;
        }

        else{
            for(int i=1; i<(pos-1); i++){
                curr=curr->next;
            } 
                    node *n=new node;
                    n->data=val;
                    n->next=curr->next;
                    curr->next->prev=n;
                    n->prev=curr;
                    curr->next=n;
                    cout<<"done at middle "<<endl; 

            
        }
        len++;
    }

    void insertEnd(int val){
        curr=head;
        if(head==NULL){
            node *n=new node;
            n->data=val;
            head=n;
            head->next=NULL;
            head->prev=NULL;
        }
        else{
            while (curr->next!=NULL)
            {
                curr=curr->next;
            }
            node *n=new node;
            n->data=val;
            curr->next=n;
            n->prev=curr;
            n->next=NULL;
        }
        len++;
    }


    void Remove(int pos){
        curr=head;
        if (head==NULL){
            cout<<"list is empty"<<endl;}
        else if(pos==1){
            head=head->next;
            delete curr;
            head->prev=NULL;
            cout<<" removed from pos 1"<<endl;}

        else{
            for(int i=1; i<pos; i++){
            temp1=curr;
            curr=curr->next;
            }

        temp1->next=curr->next;
        curr->next->prev=temp1;
        delete curr;

        cout<<"removed from "<<pos<<endl;

        }
    len--;
    }

    void RemoveByValue(int val){
        curr=head;
        if (head->data==val)
        {
            head=head->next;
            head->prev=NULL;
            delete curr;
            return;
            //head->prev=NULL;
        }

        
        else
        {
            while (curr->next!=NULL)
            {
                temp1=curr;
                if (curr->data==val)
                {
                    temp1->next=curr->next;
                    curr->next->prev=temp1;
                    delete curr;
                }
                
                curr=curr->next;  
            }
            
            if (curr->data==val)
                {
                  delete curr;
                  temp1->next=NULL;
                }
            

        }
        


    }

    void Search (int val){
        curr=head;
        if(head==NULL){
        cout<<"list is empty search is not possible "<<endl;}

        else {
            while(curr!=NULL){
                if(curr->data==val){
                cout<<"value exist in list"<<endl;}

        curr=curr->next;}
        }
    }

    void print(){
        curr=head;
        if(head==NULL){
        cout<<"no values in the list to print"<<endl;}

        else{
            cout<<"values in the array are"<<endl;
            while(curr!=NULL){
                cout<<curr->data<<endl;
                curr=curr->next;

            }

        }
    }

};




int main(){

doubly l1;
    //l1.insertion(3,1);
    //l1.insertion(2,1);
    //l1.insertion(6,2);
    //l1.insertion(8,3);
    //l1.insertion(12,4);
    //l1.insertion(10,5);

    l1.insertEnd(2);
    l1.insertEnd(4);
    l1.insertEnd(3);
    l1.insertEnd(1);
    l1.insertion(5,1);
    l1.print();

    l1.RemoveByValue(2);
    l1.RemoveByValue(4);
    //l1.RemoveByValue(3);
    l1.RemoveByValue(1);

l1.insertEnd(9);
l1.insertEnd(10);
          

    //l1.Remove(3);
    //l1.Remove(2);

    //l1.Search(10);

    l1.print();

    return 0;
}
