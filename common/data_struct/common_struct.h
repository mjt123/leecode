#pragma once
#include <list>
#include <ostream>
#include <queue>
#include <stack>
#include <string>
#include <deque>
#include <iostream>
using namespace std;
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* constructListNodes(vector<int> vec) {
  ListNode* res = new ListNode;
  ListNode* ret = res;
  for (int i = 0; i < vec.size(); ++i) {
    res->val = vec[i];
    if (i != vec.size() - 1) {
      res->next = new ListNode;
      res = res->next;
    }
  }
  return ret;
}
void printListNode(ListNode* head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}
