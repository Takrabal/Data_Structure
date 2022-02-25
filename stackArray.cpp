#include<iostream>
using namespace std;
#include <math.h>

class Stack {
  private:
    int top;
    int Size;
    int *arr;

  public:
    Stack(int s) 
    {
      top = -1;
      Size=s;
      arr=new int[Size];
    } 

    ~Stack() 
    {
        delete[] arr;
    }
      

  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == Size-1)
      return true;
    else
      return false;
  }

  void push(int val) {
    if (isFull()) {
      cout << "stack overflow" << endl;
    } else {
      top++; // 1
      arr[top] = val;
    }
  }

  int pop() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else
      {
      int popValue = arr[top];
      arr[top] = 0;
      top--;
      return popValue;
      }
    
  }

  int count() {
    return (top + 1);
  }

  int peek(int pos) {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } 
      int p=arr[pos];
      return p;
    
  }

  void change(int pos, int val) {
    arr[pos] = val;
    cout << "value changed at location " << pos << endl;
  }

  void display() {
    //cout << "All values in the Stack are " << endl;
    cout<<"evaluated answer is "<< endl;
    for (int i = Size-1; i >= 0; i--) {
      cout << arr[i] << endl;
    }
  }

  void print()
  { cout <<"evaluated answer is ";
    while (top!=-1) {
      cout<<arr[top]<<endl;
      pop();
    }
  }

  void EvaPostfix(string str) {
      for (int i=0; i<str.length(); i++) 
      {
        if (str[i]>='0' && str[i]<='9')
        {
          push(str[i]-'0');
        }

        else
        {
          int op2=pop();
          int op1=pop();

          switch (str[i])
          {
          case '+':
            push(op1+op2);
            break;
          
          case '-':
            push(op1-op2);
            break;

          case '*':
            push(op1*op2);
            break;
          
          case '/':
            push(op1/op2);
            break;

          case '^':
            push(pow(op1,op2));
            break;
          
      
          }

        }
        
        
      }
    
    print();
  }

  bool BalanceParenthesis(string s)
  {
      for (int i = 1; i < s.length(); i++)
      {
        if (s[i] == '(' || s[i] == '{' || s[i]=='[')
        {
          push(s[i]-'0');
        }
        else if (s[i] == ')')
        {
          if ( arr[top] == '(' )
          {
            pop();
          }
          else
          {
            cout<<"not balanced"<<endl;
            break;
          }
          
        }
        else if (s[i] == ']')
        {
          if (arr[top] == '[' )
          {
            pop();
          }
          else
          {
            cout<<"not balanced"<<endl;
            break;
          }
          
        }
        else if (s[i] == '}')
        {
          if (arr[top] == '{' )
          {
            pop();
          }
          else
          {
            cout<<"not balanced"<<endl;
            break;
          }
          
        }
      }
    return true;
  }

};

int main()
{   Stack s(4);
    //s.push(2);
    //s.push(4);
    //s.peek(1);
    //s.pop();

    //s.change(1,3);
    //s.display();

    s.EvaPostfix("623+-382/+*2^3+");
    
    
    s.BalanceParenthesis("((5-2)/3)");
    
    //"46+2/5*7+"
    return 0;
}