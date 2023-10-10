//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。 
//
// 算法的时间复杂度应该为 O(log (m+n)) 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums1 = [1,3], nums2 = [2]
//输出：2.00000
//解释：合并数组 = [1,2,3] ，中位数 2
// 
//
// 示例 2： 
//
// 
//输入：nums1 = [1,2], nums2 = [3,4]
//输出：2.50000
//解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
// 
//
// 
//
// 
//
// 提示： 
//
// 
// nums1.length == m 
// nums2.length == n 
// 0 <= m <= 1000 
// 0 <= n <= 1000 
// 1 <= m + n <= 2000 
// -10⁶ <= nums1[i], nums2[i] <= 10⁶ 
// 
//
// Related Topics 数组 二分查找 分治 👍 6749 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        //1.为了方便，翻转使得 nums1.size < nums2.size
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m; //指向nums1
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;

        //2.划分数组，进行二分查找，两个数组的前半段长度和要恒为总长度的一半
        while (low <= high)
        {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (low + high) / 2;
            int j = (m + n + 1) / 2 - i;

            //3. a1, a2, b1, b2 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int a1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int a2 = (i == m ? INT_MAX : nums1[i]);
            int b1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int b2 = (j == n ? INT_MAX : nums2[j]);
            //4.找到了中位数,返回结果
            if (a1 <= b2 && b1 <= a2)
                return (m + n) % 2 == 1 ? max(a1, b1) : (double )(max(a1, b1) + min(a2, b2)) / 2;
            //没找到
            else if (a1 > b2)
                high = i - 1; // high -=1;
            else
                low +=1;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
