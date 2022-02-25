#include<iostream>
using namespace std;
#include<string.h>
#include<math.h>

class Stack {
  private:
    int top;
    int Size;
    char *arr;

  public:
    Stack(int s)
    {
      top = -1;
      Size=s;
      arr=new char[Size];
    }

    ~Stack()
    {
        delete [] arr;

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

  void push(char val) {
    if (isFull()) {
      cout << "stack overflow" << endl;
    } else {
      top++; // 1
      arr[top] = val;
    }
  }

  char pop() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    }
      char popValue = arr[top];
      arr[top]='0';
      top--;
      return popValue;

  }

  char peek() {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    }
    char pr;
    pr=arr[top];
    return pr;
  }

  void change(int pos, char val) {
    arr[pos] = val;
    cout << "char changed at location " << pos << endl;
  }

  void display() {
    cout << "All values in the Stack are " << endl;
    if(isEmpty()){
    cout<<"stack underflow"<<endl;}
    for (int i = Size-1; i >= 0; i--) {
      cout << arr[i] << endl;
    }
    /*while(top!=-1)
    {
        cout<<arr[top]<<endl;
        pop();
    }*/
  }


  void BalanceParenthesis(string s)
  {
      for (int i = 1; i < s.size(); i++)
      {
        if (s[i] == '(' || s[i] == '{' || s[i]=='[')
        {
          push(s[i]);
        }
        else if (s[i] == ')')
        {

          if (arr[top]== '(' )
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
    cout<<"balanced";
  }

  void EvaPostfix(string str) {
      for (int i=0; i<str.length(); i++)
      {
        if (str[i]>='0' && str[i]<='9')
        {
          push(str[i]);
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

    display();
  }

};

int main()
{   Stack s(4);
    //s.push('t');
    //s.peek();
    //s.push('k');
    //s.push('u');
    //s.push('y');
    //s.pop();
    //s.change(2,'s');
    //s.display();


    //s.BalanceParenthesis("((5-2)/3)");

    s.EvaPostfix("623+-382/+*2^3+");

    return 0;
}
