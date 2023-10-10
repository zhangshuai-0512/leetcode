//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
// Related Topics 链表 分治 堆（优先队列） 归并排序 👍 1988 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)

//Definition for singly-linked list.
/*struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {}

    ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode *next) : val(x), next(next)
    {}
};*/

class Solution
{
public:
    /*ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;
            } else
            {
                cur->next = list2;
                cur = list2;
                list2 = list2->next;
            }
        }
        if (list1 == nullptr)
            cur->next = list2;
        else
            cur->next = list1;

        return head->next;
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *result = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            result = mergeTwoLists(result, lists[i]);
        }
        return result;

    }*/

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {   //构建优先队列，维护一个小顶堆
        auto cmp=[](ListNode* node1,ListNode* node2){return node1->val > node2->val;};
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> qu(cmp);
        //将各链表第一个节点放入优先队列
        for (auto& list : lists)
        {
           if(list!= nullptr)
               qu.push(list);
        }
        //设置头节点
        ListNode* head=new ListNode();
        ListNode* cur=head;

        //将优先队列中的节点由小到大拿出来，拼接为新的链表
        //因为链表有序，所以每次只需要比较各链表的当前头节点即可
        while(!qu.empty())
        {
            cur->next=qu.top();
            cur=cur->next;
            qu.pop();
            //每次取完链表的一个节点，要将链表的后序节点加入优先队列
            if(cur->next!= nullptr)
                qu.push(cur->next);
        }
        return head->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
