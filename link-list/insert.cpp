#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    // constructor
    Node(int x){
      data = x;
      next = nullptr;
    }
};

// Function to insert new Node at the begining
Node* insertAtFront(Node* head, int x){
  Node* newNode = new Node(x);
  newNode->next = head;
  return newNode;
}

// given the head of ll and an int and a new Node at the end returns the head
Node* insertAtEnd(Node* head, int x){
  // create the new Node 
  Node* newNode = new Node(x);
  // if empty return the new Node as head
  if(head==nullptr) return newNode;

  // store head reference in a temporary variable
  Node* last = head;

  // traverse till last node
  while(last->next !=nullptr){
    last = last->next;
  }
  // change the next pointer of the last node
  last->next = newNode;

  return head;
}

Node* insertAtPos(Node* head,int pos, int val){
  if(pos<1){
    return head;
  }
  // head will change if pos == 1
  if(pos==1){
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
  }

  Node* curr = head;

  for(int i=1; i<pos-1 && curr!=nullptr; ++i){
    curr = curr->next;
  }
  // if pos is greater than the number of nodes 
  if(curr == nullptr){
    return head;
  }
  Node* newNode = new Node(val);
  // update the next pointer 
  newNode->next = curr->next;
  curr->next    = newNode;
  return head;
}

void printList(Node* head){
  Node* curr = head;
  while(curr != nullptr){
    cout << curr->data;
    if(curr->next!=nullptr){
      cout << "->";
    }
    curr = curr->next;
  }
  cout << endl;
}

int main(){
  // created the linked list 2->3->4->5
  Node* head = new Node(2);
  head->next = new Node(3);
  head->next->next = new Node(4);
  head->next->next->next = new Node(5);

  // Insert new node at the front of the list
  int x = 1;
  head = insertAtFront(head,x);
  head = insertAtFront(head,0);
  head = insertAtEnd(head,6);
  head = insertAtPos(head,2,11);
  printList(head);
  
  return 0;
}
