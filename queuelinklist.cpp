#include <iostream>
using namespace std;

struct node 
{
    int data;
    node *next;
};

class listQueue
{
    private:
        int elements;
        node *front;
        node *back;
    public:
        listQueue()
        {
            elements = 0;
            front = back = NULL;
        }
    
    void enqueue(int value)
    {
        if (front == NULL)
        {
            node *n=new node;
            n->data = value;
            front = n;
            back = n;
            back->next = NULL;
            elements++;
        }

        else
        {
            node *n=new node;
            n->data = value;
            back->next = n;
            n->next = NULL;
            back=n;
            elements++;
        }
        
    }

    void dequeue()
    {
        if(elements==0)
        {
            cout<<"queue underflow"<<endl;
        }

        else
        {
            node *temp=front;
            front=front->next;
            delete temp;
            temp=NULL;
            elements--;
        }
        
    }

    void display()
    {
        if (elements==0)
        {
            cout<<"queue underflow"<<endl;
        }

        else
        {
            while (front!=NULL)
            {
                cout<<front->data<<endl;
                dequeue();
            }
            
        }
           
    }
        
};

int main()
{
    listQueue q;
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    
    return 0;
}