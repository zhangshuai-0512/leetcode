//给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。 
//
// 
// 
//
// 
//
// 示例 1： 
// 
// 
//输入：head = [4,2,1,3]
//输出：[1,2,3,4]
// 
//
// 示例 2： 
// 
// 
//输入：head = [-1,5,3,4,0]
//输出：[-1,0,3,4,5]
// 
//
// 示例 3： 
//
// 
//输入：head = []
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// 链表中节点的数目在范围 [0, 5 * 10⁴] 内 
// -10⁵ <= Node.val <= 10⁵ 
// 
//
// 
//
// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？ 
//
// Related Topics 链表 双指针 分治 排序 归并排序 👍 2100 👎 0

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

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        //2.治：只剩一个节点就返回
        if (!head || !head->next)
            return head;
        //1.分：递归的将将链表分为两段，直到每一段只剩一个节点
        ListNode *mid = findMid(head);
        ListNode *newHead = mid->next;
        mid->next = nullptr; //将链表断开
        ListNode *left = sortList(head);
        ListNode *right = sortList(newHead);
        //3.合：合并两个链表
        return merge(left, right);
    }

    //查找链表的中间节点
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    //递归的将两个有序链表合并为一个有序链表
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val <= l2->val)
        {
            l1->next = merge(l1->next, l2);
            return l1;
        } else
        {
            l2->next = merge(l1, l2->next);
            return l2;
        }
       /* if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head=new ListNode();
        ListNode* tmp=head;
        while(l1!= nullptr && l2!= nullptr)
        {
            if(l1->val < l2->val)
            {
                tmp->next=l1;
                l1=l1->next;
            }
            else
            {
                tmp->next=l2;
                l2=l2->next;
            }
            tmp=tmp->next;
        }
        if(l1== nullptr)
            tmp->next=l2;
        else
            tmp->next=l1;
        return head->next;*/
    }
};
//leetcode submit region end(Prohibit modification and deletion)
