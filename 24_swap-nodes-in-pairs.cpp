//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]
// 
//
// 示例 2： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1]
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 100] 内 
// 0 <= Node->val <= 100
// 
// Related Topics 递归 链表 👍 1413 👎 0

#include<bits/stdc++->h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list->
 */
 /*struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };*/

/*class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return head;
        if (head->next == nullptr)
            return head;

        ListNode *first = head;
        ListNode *second = first->next;
        head=head->next;
        ListNode* temp = new ListNode(-1);
        temp->next=head;
        while (first != nullptr && second != nullptr)
        {
            first->next = second->next;
            second->next = first;
            temp->next=second;
            temp=first;

            first = first->next;
            if (first!= nullptr)
            {
                second = first->next;
            }
            else
            {
                second= nullptr;
            }
        }
        return head;
    }
};*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 如果链表为空或者只有一个节点，则直接返回
        if (head == nullptr || head->next == nullptr)  return head;
        ListNode* p = head;
        ListNode* q = head->next;
        while (q&&p)
        {
            int temp = p->val;
            p->val = q->val;
            q->val = temp;
            if (!q->next)  return head;
            p = q->next;
            q = p->next;
        }
        return head;
    }
};
//leetcode submit region end(Prohibit modification and deletion)