#include <iostream>
using namespace std;

class Queue
{
private:
       int *arr;
       int size;
       int rear;
       int front;
       int elements;

public:
    Queue(int s)
    {
        size = s;
        rear=-1;
        front=0;
        elements = 0;
        arr=new int[size];
    }
    ~Queue()
    {
        delete []arr;
    }

    void enqueue(int value)
    {
        if (elements==size-1)
        {
            cout<<"Queue overflow"<<endl;
        }

        else if (rear==size-1)
        {
            rear=0;
        }

        else
        {
            rear++;
            arr[rear]=value;
            elements++;
        }
           
    }

    int dequeue()
    {   int val;
        if (elements==0)
        {
            cout<<"Queue underflow"<<endl;
        }
         
        else if (front==size-1)
        {
            front=0;
        }

        else
        {
            val=arr[front];
            front++;
            elements--;
        }

        return val;
        
    }

    void display()
    {
        if (elements==0)
        {
            cout<<"Queue underflow"<<endl;
        }

        else
        {
            while (elements!=0)
            {
                cout<<arr[front]<<endl;
                dequeue();
            }
            
        }
            
    }

};


int main()
{
    Queue q(5);
    q.enqueue(4);
    q.enqueue(3);
    q.enqueue(6);
    q.display();
    q.dequeue();
}


