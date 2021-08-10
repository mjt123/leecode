#include "common/data_struct/common_struct.h"
#include "common/utilty/debug_message.h"
/**
 *
 * 存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。



示例 1：


输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]
**/
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* res = new ListNode();
    res->next = head;
    head = res;
    while (head && head->next) {
      while (head->next->val == head->next->next->val) {
        head->next = head->next->next->next;
        if (!head->next || !head->next->next) {
//          goto label;
          break;
        }
      }

      head = head->next;
    }
//label:
    return res->next;
  }
};
int main() {
  ListNode* head = constructListNodes({1, 1, 1, 2, 3});
  Solution solution;
  solution.deleteDuplicates(head);
  printListNode(head);
  return 0;
}
