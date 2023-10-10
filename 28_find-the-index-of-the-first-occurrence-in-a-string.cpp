//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
// 
//
// 示例 2： 
//
// 
//输入：haystack = "leetcode", needle = "leeto"
//输出：-1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack 和 needle 仅由小写英文字符组成 
// 
//
// Related Topics 双指针 字符串 字符串匹配 👍 1884 👎 0

#include<bits/stdc++.h>

using namespace std;
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int j=0;
        int h_len=haystack.length();
        int n_len=needle.length();
        int next[n_len];
        getNext(next,needle);

        for(int i=0; i<h_len;i++)
        {
            while(j>0 && haystack[i]!=needle[j])
            {
                j=next[j-1];
            }
            if(haystack[i]==needle[j])
                j++;
            if(j==n_len)
            {
                return i-n_len+1;
            }
        }
        return -1;
    }

    void getNext(int *next, const std::string &s)
    {
        int now = 0;
        next[0] = 0;
        for (int x = 1; x < s.size(); x++)
        {
            while (now > 0 && s[x] != s[now])
            { // now要保证大于0，因为下面有取now-1作为数组下标的操作
                now = next[now - 1]; // 注意这里，是要找前一位的对应的回退位置了
            }
            if (s[x] == s[now])
            {
                now++;
            }
            next[x] = now;
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
