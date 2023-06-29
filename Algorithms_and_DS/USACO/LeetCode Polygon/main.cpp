#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int x) : data(x), next(nullptr) {}
};

void printList(Node* head)
{
  if(head==nullptr)
    return;
  printList(head->next);
  std::cout << head->next->data << " ";
}

int main()
{
  Node* curr = new Node(0);
  int index = 0;
  while(index < 10)
  {
    curr->next = new Node(index);
    curr = curr->next;
    ++index;
  }
  printList(curr);
}