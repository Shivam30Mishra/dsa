#include<bits/stdc++.h>
using namespace std;

class Node{
  // definition of node in singly linked list
  public:
    int data;
    Node* next;

    // constructor to initialize the node with data 
    Node(int data){
      this->data = data;
      this->next = NULL;
    }
};

int main(){
  Node* head =  new Node(10);
  head->next =  new Node(20);
  head->next->next = new Node(30);
  head->next->next->next = new Node(40);

  // printing the linked list
  Node* temp = head;
  while(temp != nullptr){
    cout << temp->data << " ";
    temp = temp->next;
  }
}
