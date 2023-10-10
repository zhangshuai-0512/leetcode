//给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aacecaaa"
//输出："aaacecaaa"
// 
//
// 示例 2： 
//
// 
//输入：s = "abcd"
//输出："dcbabcd"
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 仅由小写英文字母组成 
// 
//
// Related Topics 字符串 字符串匹配 哈希函数 滚动哈希 👍 532 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool check(string &s,int start,int end)
    {
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    string shortestPalindrome(string s)
    {
        if(s.empty())
            return "";
        int len=s.size();
        int index=0;
        for(int i=len-1;i>0;i--)
        {
            if(check(s,0,i))
            {
                index=i;
                break;
            }
        }
        string s1= s.substr(index+1,len-1);
        reverse(s1.begin(),s1.end());
        s=s1+s;
        return s;

    }

};
//leetcode submit region end(Prohibit modification and deletion)
