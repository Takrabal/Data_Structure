#include <iostream>
using namespace std;


class stack{
    private:
        int *stk;
        int *top;
        int Size;

    public:
        stack(int s){ 
            top=NULL;
            Size=s;

            stk=new int[Size];
        }

        ~stack(){
            delete[] stk;
        }

    int push(int val){
        if (top==stk+Size-1)
        {
            cout<<"stackoverflow"<<endl;
        
        }
        else if (top==NULL)
        {
            top=stk;
            *top=val;
        
        }

        top++;
        *top=val;
        return *top;
    }
    void pop(){
        if (top==NULL)
        {
            cout<<"underflow"<<endl;
        }
        else if (top==stk)
        {
            top=NULL;
            return;
        }
        top--;
        return;
    }

    void print()
    {
        while(top!=NULL)
        {
            cout<<*top<<endl;
            pop();
        }
    }


};

int main(){

    stack s(5);

    s.push(3);
    s.push(4);
    s.print();
    s.pop();

    //s.print();

    return 0;
}