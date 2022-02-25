#include <iostream>
using namespace std;


struct node {
int data;
node *next;
};

class linkedlist{
    private:
        node *head;
        node *curr, *prev;
        int length;

    public:
        linkedlist(){
        head=curr=prev=NULL;
        length=0;}


        void insertion (int val,int pos){
        curr=head;
        if(pos==1){
            node *n=new node;
                n->data=val;
                n->next=head;
                head=n;

                }

        for(int i=2; curr!=NULL; i++){
                    if(pos==i){
                        node *n= new node;
                        n->data=val;

                        n->next=curr->next;
                        curr->next=n;

                    }

                    curr=curr->next;}

}

    void insertEND(int val){
        curr=head;
        while (curr->next!=NULL)
        {
            curr=curr->next;
        }
        node *n=new node;
        n->data=val;
        curr->next=n;
        n->next=NULL;
        length++;
    }

void Remove(int pos){
    curr=head;
    if(head==NULL){
    cout<<"LIST IS EMPTY"<<endl;}
    else if(pos==1){
    head=head->next;
    delete curr;}

    else{
    for (int i=1; i<pos; i++){
        prev=curr;
        curr=curr->next;
    }
    prev->next=curr->next;
    delete curr;
    length--;

    }

}

void Search(int val){
    curr=head;
    if(head==NULL){
    cout<<"list is empty you can not search anything"<<endl;}

    while(curr!=NULL){
        if(curr->data==val){
            cout<< "exist"<<endl;
    }
    curr=curr->next;

    }

    }

void print(){
curr=head;
if(head==NULL){
    cout<<"list is empty"<<endl; }
else {
        while(curr!=NULL){

        cout<<curr->data<<endl;
        curr=curr->next;}
}

}


};




int main()
{

    linkedlist l1;
    l1.insertion(2,1);
    l1.insertion(3,2);
    l1.insertion(5,3);
    l1.insertion(8,4);
    l1.insertEND(7);
    l1.insertEND(9);

    //l1.Remove(6);
    l1.print();

    return 0;

}
