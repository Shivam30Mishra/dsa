#include<bits/stdc++.h>
using namespace std;

class StackArray{
  private:
    int arr[100];
    int top;

  public:
    StackArray(){
      top = -1;
    }

    bool isEmpty(){
      if(top==-1){
        return true;
      }
      return false;
    }

    void push(int x){
      if(top==99){
        cout << "Stack Overflow\n";
      }
      arr[++top] = x;
    }

    int pop(){
      if(isEmpty()){
        cout << "Stack Underflow\n";
        return -1;
      }
      return arr[top--];
    }

    int peek(){
      if(isEmpty()){
        cout << "Stack Empty\n";
        return -1;
      }
      return arr[top];
    }

    int size(){
      return top+1;
    }
};

int main(){
  StackArray s;
  s.push(10);
  s.push(20);
  s.push(30);

  cout << "Top : " << s.peek() << endl;
  cout << "Pop : " << s.pop()  << endl;
  cout << "Size: " << s.size() << endl;

  return 0;
}
