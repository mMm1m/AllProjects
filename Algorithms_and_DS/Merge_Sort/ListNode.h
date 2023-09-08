#ifndef MERGE_SORT_LISTNODE_H
#define MERGE_SORT_LISTNODE_H

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

#endif //MERGE_SORT_LISTNODE_H
