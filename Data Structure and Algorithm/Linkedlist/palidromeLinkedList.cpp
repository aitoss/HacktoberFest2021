/*Check if a Linked list is palindrome or not*/
//Contributed by Vivek Singh
#include <bits/stdc++.h>

using namespace std;

struct Node{
  int data;
  Node *next;
  Node(int x){
    data=x;
    next=NULL;
  }
};

void printList(Node *head){
  Node *cur=head;
  while(cur!=NULL){
    cout << (cur->data) << ' ';
    cur=cur->next;
  }
  cout << '\n';
}

Node *insertEnd(Node *head,int x){
  Node *temp = new Node(x);
  
  if(head==NULL){
    return temp;
  }
  
  Node *cur=head;
  while(cur->next!=NULL){
    cur=cur->next;
  }
  cur->next=temp;
  
  return head;
}

Node *reverseList(Node *head){
  Node *cur=head;
  Node *last=NULL;
  while(head!=NULL){
    cur=head;
    head=head->next;
    cur->next=last;
    last=cur;
  }
  
  return cur;
}

bool isPalindromeList(Node *head){
  Node *slow=head;
  Node *fast=head;
  while(fast->next!=NULL && fast->next->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
  }
    
  Node *rev=reverseList(slow->next);
  Node *cur=head;
  while(rev!=NULL){
    if(rev->data!=cur->data){
      return false;
    }
    rev=rev->next;
    cur=cur->next;
  }
  
  return true;
}

int main(){
  Node *head = NULL;
    
  head=insertEnd(head,10);
  head=insertEnd(head,20);
  head=insertEnd(head,30);
  head=insertEnd(head,30);
  head=insertEnd(head,20);
  head=insertEnd(head,10);

  printList(head);

  if(isPalindromeList(head))cout << "Yes" << '\n';
  else cout << "No" << '\n';

  return 0;
}
/*
We can do this easily by first reaching the middle element and then reversing the linked-list
on right of middle element and comparing both halves of our linked-list. For even cases we
have two middle elements and we will choose the first middle element because next of it marks 
the beginning of second half of our linked-list.
*/