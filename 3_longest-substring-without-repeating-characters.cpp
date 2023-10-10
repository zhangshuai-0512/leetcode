//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 5 * 10⁴ 
// s 由英文字母、数字、符号和空格组成 
// 
// Related Topics 哈希表 字符串 滑动窗口 👍 7609 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int Max(int x,int y)
    {
        return x>y? x:y;
    }
    int lengthOfLongestSubstring(string s)
    {
            int len=s.length();
            if(s[0]==' ' || len==1)
                return 1;

            int left=0;//左指针
            int right=0;//右指针
            int max=0;//最大窗口长度
            //map数组保存字符索引，对应ASII表
            int map[127]={-1};
            for(int i=0;i<127;i++)
            {
                map[i]=-1;
            }
            //字符重不重复，右指针都扩大，直到末尾； 重复了的话左指针右移缩小窗口
            while(right<len)
            {
                if(map[s[right]]>=left)
                {//如果s[rigth]字符的索引大于=left，说明此字符存在于left和right之间（即有重复），
                 //左窗口指针右移到重复字符后面一位,缩小窗口
                    left=map[s[right]]+1;//
                }
                //否则继续扩大窗口，记录新的字符索引
                map[s[right]]=right;
                right+=1;
                max=Max(max,right-left);//记录新的窗口值
            }
            return max;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
