//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。 
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。 
//
// 
//
// 
//
// 示例 1： 
//
// 
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// 示例 2： 
//
// 
//输入：digits = ""
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：digits = "2"
//输出：["a","b","c"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= digits.length <= 4 
// digits[i] 是范围 ['2', '9'] 的一个数字。 
// 
//
// Related Topics 哈希表 字符串 回溯 👍 2619 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<string> teleMap = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result; //存储结果
    string digits;

    vector<string> letterCombinations(string digits)
    {
        if(digits.length()==0)
            return{};
        this->digits=digits;
        string str="";
        backtracking(0,str);
        return result;
    }

    void backtracking(int index, string str)
    {   //1.digits遍历完成，结束
        if(index>=digits.length())
        {
            result.push_back(str);
            return;
        }
        int teleNum = digits[index] - '0';//电话符串的一个数字
        string letters=teleMap[teleNum]; //数字对应的字符串
        for (int i = 0; i < letters.size(); ++i)
        {   //2.递归将字符拼接到字符串str后
            char ch=letters[i];
            str.push_back(ch);
            backtracking(index+1, str);
            //3.回溯
            str.pop_back();
            /*在本层递归中添加，就要在在递归里手动回溯，如果在下一层添加，会自动回溯
            backtracking(index+1, str+ch);*/
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)
