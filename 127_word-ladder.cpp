//字典 wordList 中从单词 beginWord 和 endWord 的 转换序列 是一个按下述规格形成的序列
// beginWord -> s1 -> s2 -> ... -> sk： 
//
// 
// 每一对相邻的单词只差一个字母。 
// 
// 对于 1 <= i <= k 时，每个
// si 都在
// wordList 中。注意， beginWord 不需要在
// wordList 中。
// 
// sk == endWord 
// 
//
// 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 
//中的 单词数目 。如果不存在这样的转换序列，返回 0 。 
//
// 示例 1： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot",
//"log","cog"]
//输出：5
//解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
// 
//
// 示例 2： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot",
//"log"]
//输出：0
//解释：endWord "cog" 不在字典中，所以无法进行转换。 
//
// 
//
// 提示： 
//
// 
// 1 <= beginWord.length <= 10 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 5000 
// wordList[i].length == beginWord.length 
// beginWord、endWord 和 wordList[i] 由小写英文字母组成 
// beginWord != endWord 
// wordList 中的所有字符串 互不相同 
// 
//
// Related Topics 广度优先搜索 哈希表 字符串 👍 1279 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        //将vector转换为set，方便搜索
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        //如果endWord不在单词列表中，返回0
        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        //用vidited记录到达 当前单词的路径长度，拥有长度的也就是访问过的
        unordered_map<string, int> visited;
        //beginWord路径长度为1
        visited.insert({beginWord, 1});

        //beginWord入对
        queue<string> qu;
        qu.push(beginWord);
        while (!qu.empty())
        {   //取出当前单词
            string curWord = qu.front();
            qu.pop();
            int minLen = visited[curWord];
            //将单词的每个字母更换为26个字母，构成新单词
            for (int i = 0; i < curWord.size(); i++)
            {
                string newWord = curWord;
                for (int j = 0; j < 26; j++)
                {
                    newWord[i] = j + 'a';
                    //新单词就是endWord则返回
                    if (newWord == endWord)
                        return minLen + 1;
                    //新单词不是就是endWord，但存在于单词列表中，就作为下一个单词（图的邻接点）入队
                    if (wordSet.find(newWord) != wordSet.end() && visited.find(newWord) == visited.end())
                    {
                        visited.insert({newWord, minLen + 1});
                        qu.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


