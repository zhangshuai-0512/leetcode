//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
// 
//
// 示例 2： 
//
// 
//输入：head = [1], n = 1
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：head = [1,2], n = 1
//输出：[1]
// 
//
// 
//
// 提示： 
//
// 
// 链表中结点的数目为 sz 
// 1 <= sz <= 30 
// 0 <= Node.val <= 100 
// 1 <= n <= sz 
// 
//
// 
//
// 进阶：你能尝试使用一趟扫描实现吗？ 
// Related Topics 链表 双指针 👍 2068 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)

 // Definition for singly-linked list.
 /* struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *prefix=new ListNode();
        prefix->next=head;
        ListNode *fast = head;
        ListNode *slow = prefix;
        //移动快慢指针到相应位置
        while(--n && fast!= nullptr)
            fast=fast->next;
        if(n!=0)
            return head;
        //将快指针移到结尾节点，满指针指向要删除的节点的前一个
        while(fast->next!= nullptr)
        {
            slow=slow->next;
            fast=fast->next;
        }
        //删除节点
        ListNode *tmp=slow->next;
        slow->next=tmp->next;
        delete tmp;
        return prefix->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
