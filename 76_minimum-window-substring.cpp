//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 
//
// 注意： 
//
// 
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
//解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
//解释：整个字符串 s 是最小覆盖子串。
// 
//
// 示例 3: 
//
// 
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// m == s.length 
// n == t.length 
// 1 <= m, n <= 10⁵ 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 
//o(m+n) 时间内解决此问题的算法吗？
//
// Related Topics 哈希表 字符串 滑动窗口 👍 2636 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mapT;//保存t中字符出现的次数
        unordered_map<char, int> mapWindow;//保存窗口window中的字符出现的次数
        for (int i = 0; i < t.length(); ++i)
        {//统计t中的字符
            mapT[t[i]]++;
        }
        int count = 0; //记录窗口中涵盖了count个t中的字符
        int resStart = 0; //记录结果的起始索引
        int minLen = INT_MAX; //最小窗口长度
        int left = 0, right = 0;  //左右窗口

        //遍历字符串s
        while (right < s.length())
        {
            //1.更新右窗口字符计数
            mapWindow[s[right]]++; //统计字符出现次数
            if (mapT.count(s[right]) && mapWindow[s[right]] == mapT[s[right]])
            {//如果字符a在t和window中出现的次数相等，就增加count的计数，表明此字符够了
                ++count;
            }

            //2.符合条件，更新结果，缩小窗口。
            while (count == mapT.size())
            {//如果窗口完全涵盖了t中的字符，更新最小窗口长度
                if (right - left + 1 < minLen)
                {
                    resStart = left;
                    minLen = right - left + 1;
                }
                mapWindow[s[left]]--; //更新左窗口计数
                if (mapT.count(s[left]) && mapT[s[left]] > mapWindow[s[left]])
                {//更新count计数，如果窗口中s[left]字符计数小于t中的数量，count-1
                    --count;
                }
                ++left; //缩小窗口
            }

            //3.右窗口右移，扩大窗口
            ++right;
        }

        if (minLen == INT_MAX)
            return "";
        return s.substr(resStart, minLen);
    }
};


//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution *s = new Solution();
    auto result = s->minWindow("ADOBECODEBANC", "ABC");
    cout << result << " ";
}