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
    if (!head) {
      return head;
    }

    ListNode* dummy = new ListNode(0, head);

    ListNode* cur = dummy;
    while (cur->next && cur->next->next) {
      if (cur->next->val == cur->next->next->val) {
        int x = cur->next->val;
        while (cur->next && cur->next->val == x) {
          cur->next = cur->next->next;
        }
      } else {
        cur = cur->next;
      }
    }

    return dummy->next;
  }
};
int main() {
  ListNode* head = constructListNodes({1, 1, 1, 2, 3});
  Solution solution;
  ListNode* res = solution.deleteDuplicates(head);
  printListNode(res);
  return 0;
}
