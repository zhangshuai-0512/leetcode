//给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。 
//
// s 中的 串联子串 是指一个包含 words 中所有字符串以任意顺序排列连接起来的子串。 
//
// 
// 例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，
//"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。 
// 
//
// 返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "barfoothefoobarman", words = ["foo","bar"]
//输出：[0,9]
//解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
//子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
//子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
//输出顺序无关紧要。返回 [9,0] 也是可以的。
// 
//
// 示例 2： 
//
// 
//输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
//输出：[]
//解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
//s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
//所以我们返回一个空数组。
// 
//
// 示例 3： 
//
// 
//输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
//输出：[6,9,12]
//解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
//子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
//子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
//子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 10⁴ 
// 1 <= words.length <= 5000 
// 1 <= words[i].length <= 30 
// words[i] 和 s 由小写英文字母组成 
// 
//
// Related Topics 哈希表 字符串 滑动窗口 👍 990 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        int sLen = s.size();
        int wordNum = words.size();
        int wordLen = words[0].size();
        vector<int> result;
        unordered_map<string, int> wordMap;
        for (int i = 0; i < wordNum; ++i)
        {//采用unordered_map存储单词，方便查找和插入
            if (wordMap.find(words[i]) != wordMap.end())
                wordMap[words[i]] += 1;
            wordMap.insert({words[i], 1});
        }

        //遍历字符串，进行wordLen次滑动窗口操作
        for (int i = 0; i < wordLen; ++i)
        {
            //左右窗口
            int left = i;
            int right = i;
            unordered_map<string, int> mp; //临时map，记录窗口中单词出现次数

            while (right + wordLen <= sLen && left <= right)
            {   //1.遍历字符串,不断扩大窗口
                while (right + wordLen <= sLen && right - left  < wordNum * wordLen)
                {
                    string word = s.substr(right, wordLen); //截取单词
                    if (wordMap.find(word) == wordMap.end())
                    {//1.1截取的单词不在单词列表，右窗口移动wordLen个长度，左窗口移到有窗口左边
                        left = right ;
                        right = right + wordLen;
                        mp.clear();
                    }
                    //1.2截取的单词在单词列表
                    else
                    {
                        if (mp[word] < wordMap[word])
                        {//1.2.1截取的单词 在mp中存在，数量没有超出要求，则计数加1,右窗口扩大wordLen
                            mp[word] ++;
                            right += wordLen;
                        }
                        else if (mp[word] >= wordMap[word])
                        {//1.2.1截取的单词 在mp中存在，但数量已经超出要求，则循环缩小左窗口，每次缩小wordLen，直至截取单词数量满足要求
                            string tmp = s.substr(left, wordLen);
                            while (tmp != word)
                            {
                                if (mp[tmp] > 1)
                                    mp[tmp]--;
                                else
                                    mp.erase(tmp);
                                left += wordLen;
                                tmp = s.substr(left , wordLen);
                            }
                            mp[word]--;
                            left += wordLen;
                        }
                    }
                }

                //2.如果两个map内容相等，说明找到一个结果，存储结果，收缩窗口
                if (mp == wordMap)
                {
                    result.push_back(left);
                    string word = s.substr(left, wordLen);
                    if (mp[word] > 1)
                        mp[word]--;
                    else
                        mp.erase(word);
                }
                left += wordLen;
            }
        }
        return result;
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main()
{
    Solution *s = new Solution();
    vector<string> words = {"c","b","a","c","a","a","a","b","c"};
    auto result = s->findSubstring("bcabbcaabbccacacbabccacaababcbb", words);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << " ";
    }
}