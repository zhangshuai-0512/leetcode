//给你一个非负整数 x ，计算并返回 x 的 算术平方根 。 
//
// 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。 
//
// 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。 
//
// 
//
// 示例 1： 
//
// 
//输入：x = 4
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：x = 8
//输出：2
//解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= x <= 2³¹ - 1 
// 
//
// Related Topics 数学 二分查找 👍 1339 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 1 || x == 2)
            return 1;

        int left = 1;
        int right = (x / 2); //令x=2y,当y大于2时，则y*y>2x，因此右边界最大到x即可
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            long long y = mid * mid;
            long long z = (mid + 1) * (mid + 1);
            //对于题目要求，如果x恒等于mid平方， 或者x在mid和mid+1的平方中间,则mid为x的平方根
            if (y == x || (y < x && x < z))
                return mid;
            else if (y > x)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
