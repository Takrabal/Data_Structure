#include<iostream>
using namespace std;
#include <math.h>

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
    } else {
      char popValue = arr[top];
      arr[top] = ' ';
      top--;
      return popValue;
    }
  }

  int count() {
    return (top + 1);
  }

  char peek(int pos) {
    if (isEmpty()) {
      cout << "stack underflow" << endl;
      return 0;
    } else {
        char p=arr[pos];
      return p;
    }
  }

  void change(int pos, char val) {
    arr[pos] = val;
    cout << "char changed at location " << pos << endl;
  }

  void display() {
    //cout << "All values in the Stack are " << endl;
    cout<<"evaluated answer is "<< endl;
    for (int i = Size-1; i >= 0; i--) {
      cout << arr[i] << endl;
    }
  }


  bool BalanceParenthesis(string s)
  {
      for (int i = 1; i < s.length(); i++)
      {
        if (s[i] == '(' || s[i] == '{' || s[i]=='[')
        {
          push(s[i]);
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
{   Stack s(7);
    s.push('t');
    s.peek(1);
    //s.change(1,3);
    //s.display();

    //s.EvaPostfix("623+-382/+*2^3+");
    
    s.BalanceParenthesis("((5-2)/3)");
    
    //"46+2/5*7+"
    return 0;
}