//给你一个字符串 s，找到 s 中最长的回文子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
// Related Topics 字符串 动态规划 👍 5230 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() < 2)
            return s;
        if (s.length() == 2)
        {
            if (s[0] == s[1])
                return s;
            else
                return s.substr(0, 1);
        }

        int maxLen = 1;
        int l = 0;
        int r = 0;
        int index = 0;
        for (int i = 0; i < s.length(); i++)
        {
            l = i-1;
            r = i+1;
            while (l>= 0 && s[l] == s[i])
                l -= 1;
            while (r < s.length() && s[r] == s[i])
                r += 1;
            while (l >= 0 && r < s.length() && s[l] == s[r])
            {

                l -= 1;
                r += 1;
            }
            if (r - l + 1 > maxLen)
            {
                maxLen = r - l + 1;
                index = l;
            }
        }
        return s.substr(index+1,maxLen-2);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution *st = new Solution();
    string s = st->longestPalindrome("ababd");
    std::cout << s << endl;
}
/*
本题最容易想到的一种方法应该就是 中心扩散法。
中心扩散法怎么去找回文串？
从每一个位置出发，向两边扩散即可。遇到不是回文的时候结束。
举个例子，str = acdbbdaastr=acdbbdaa 我们需要寻找从第一个 b（位置为 33）出发最长回文串为多少。怎么寻找？
    (1)首先往左寻找与当期位置相同的字符，直到遇到不相等为止。
    (2)然后往右寻找与当期位置相同的字符，直到遇到不相等为止。
       上面两步可以找到一串字符都相同的字符串，然后向两边扩展。
    (3)最后左右双向扩散，直到左和右不相等。如下图所示：
*/

