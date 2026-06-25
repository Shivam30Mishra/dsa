#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    // constructor
    Node(int x){
      this->data = x; 
      this->next = nullptr;
    }
};

Node* deleteHead(Node* head){
  // check if list is empty
  if(head==nullptr){
    return nullptr;
  }
  Node* temp = head;
  head = head->next;
  delete temp;
  return head;
}

void printList(Node* curr){
  while(curr!=nullptr){
    cout << curr->data;
    if(curr->next!=nullptr){
      cout << "->";
    }
    curr = curr->next;
  }
}

Node* deleteLast(Node* head){
  if(head==nullptr)return nullptr;
  // if list has only one node delete it and return nullptr 
  if(head->next==nullptr){
      delete head;
      return nullptr;
  }
  // find the second last node 
  Node* secondLast = head;
  while(secondLast->next->next != nullptr){
    secondLast = secondLast->next;
  }
  // delete the last node 
  delete secondLast->next;

  // change next of secondLast 
  secondLast->next = nullptr;

  return head;
}

Node* deleteNode(Node* head, int position){
  Node* temp = head;
  // head is to be declared
  if(position==1){
    head = temp->next;
    delete temp;
    return head;
  }
  // traverse to the node before the one to be deleted 
  Node* prev = nullptr;
  for(int i=1; i<position; i++){
    prev = temp;
    temp = temp->next;
  }
  // Delete the node at the position 
  prev->next = temp->next;
  delete temp;
  return head;
}

int main(){
  Node* head = new Node(8);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(1);
  head->next->next->next->next = new Node(1);
  head = deleteHead(head);
  head = deleteLast(head);
  head = deleteNode(head,2);
  printList(head);

  return 0;
}
