#include <iostream>

class ListNode
{
  public:
   ListNode();
   ListNode(int);
   ListNode(int, ListNode*);
   ~ListNode() = default;
   int val;
   ListNode* next;
};

ListNode::ListNode() : val(0), next(nullptr){}
ListNode::ListNode(int v) : val(v), next(nullptr) {}
ListNode::ListNode(int v, ListNode* node) : val(v), next(node) {}


void getSublists(ListNode* src, ListNode** start_dest, ListNode** end_dest)
{
  ListNode* slow;
  ListNode* fast;
  slow = src;
  fast = src->next;
  while(fast != nullptr)
  {
    fast = fast->next;
    if(fast != nullptr)
    {
      fast = fast->next;
      slow = slow->next;
    }
  }
  *start_dest = src;
  *end_dest = slow->next;
  slow->next = nullptr;
}
ListNode* merge(ListNode* a, ListNode* b)
{
  if(a == nullptr)
  {
    return (b);
  }
  if(b == nullptr)
  {
    return (a);
  }
  ListNode* result = nullptr;
  if(a->val <= b->val)
  {
    result = a;
    result->next = merge(a->next,b);
  }
  else
  {
    result = b;
    result->next = merge(a,b->next);
  }
  return (result);
}


void MergeSort(ListNode** ref)
{
  ListNode* root = *ref;
  ListNode* a;
  ListNode* b;
  if(root == nullptr || root->next == nullptr)
    return;
  getSublists(root, &a, &b);
  MergeSort(&a);
  MergeSort(&b);
  *ref = merge(a,b);
}

ListNode* sortList(ListNode* head)
{
  MergeSort(&head);
  return head;
}


int main()
{
  ListNode* head = new ListNode();
  ListNode* tmp = head;
  int n; std::cin >> n;
  for(int i = 0; i < n; ++i)
  {
    int value; std::cin >> value;
    ListNode* node = new ListNode(value);
    tmp->next = node;
    tmp = tmp->next;
  }
  sortList(head);
  head = head->next;
  while(head != nullptr)
  {
    std::cout << head->val << " ";
    head = head->next;
  }
}
