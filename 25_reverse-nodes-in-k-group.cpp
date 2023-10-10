//给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。 
//
// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。 
//
// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。 
//
// 
//
// 示例 1： 
//
// 
//输入：head = [1,2,3,4,5], k = 2
//输出：[2,1,4,3,5]
// 
//
// 示例 2： 
//
// 
//
// 
//输入：head = [1,2,3,4,5], k = 3
//输出：[3,2,1,4,5]
// 
//
// 
//提示：
//
// 
// 链表中的节点数目为 n 
// 1 <= k <= n <= 5000 
// 0 <= Node.val <= 1000 
// 
//
// 
//
// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？ 
//
// 
// 
// Related Topics 递归 链表 👍 1661 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 /*算法思想：尾插法*/

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if(head== nullptr)
            return head;
        ListNode* per= new ListNode(-1);
        per->next=head;

        ListNode* cur=per;
        ListNode* start=head;
        ListNode* end=per;
        while(start!= nullptr)
        {
            for(int i=0;i<k;i++)
            {
                if(end->next!= nullptr)
                    end=end->next;
                else
                    return per->next;
            }
            for(int i=1;i<k;i++)
            {
               cur->next=start->next;
               start->next=end->next;
               end->next=start;
               start=cur->next;
            }
            for(int i=1;i<k;i++)
            {
                if(start->next!= nullptr)
                    start=start->next;
                else
                    return per->next;
            }
            cur=start;
            end=start;
            start=start->next;
        }

        return per->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
