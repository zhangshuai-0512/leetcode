//给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。 
//
// 注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。 
//
// 
//
// 示例 1： 
//
// 
//输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
// 
//
// 示例 2： 
//
// 
//输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
//     注意，你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 
//输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 300 
// 1 <= wordDict.length <= 1000 
// 1 <= wordDict[i].length <= 20 
// s 和 wordDict[i] 仅有小写英文字母组成 
// wordDict 中的所有字符串 互不相同 
// 
// Related Topics 字典树 记忆化搜索 哈希表 字符串 动态规划 👍 1616 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {   //用set存储单词表，方便查找
        unordered_set<string> hash;
        for (string word : wordDict)
        {
            hash.insert(word);
        }

        int bagweight = s.size();//背包容量，即字符串s的长度
        //1.dp[i] : 表示长度为i的字符串，是否可以拆分为一个或多个在字典中出现的单词
        vector<bool> dp(bagweight + 1, false);
        //2.根据递推公式，dp[0]=true,否则后面的状态无法改变，全为false
        dp[0] = true;
        //3.完全背包求排序，先遍历背包
        for (int j = 1; j <= bagweight; j++)
        {//遍历背包,即字符串s
            for (int i = 0; i < j; i++)
            {//遍历物品，即字符串列表
                if (dp[i] && hash.find(s.substr(i, j - i)) != hash.end())
                {//如果字符串s(0-i)可以由字符串列表组成，并且s(i-j)存在于字符串列表,则dp[j]=true
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[bagweight];
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution *ss = new Solution();

    vector<string> v;
    v.push_back("leet");
    v.push_back("code");
    bool result = ss->wordBreak("leetcode", v);
    cout << result;
}