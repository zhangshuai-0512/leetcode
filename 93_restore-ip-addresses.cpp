//有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
// 
//
// 给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新
//排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 20 
// s 仅由数字组成 
// 
//
// Related Topics 字符串 回溯 👍 1303 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    vector<string> result;
    vector<string> path;

    vector<string> restoreIpAddresses(string s)
    {
        backtracking(s, 0);
        return result;
    }

    void backtracking(const string &s, int startIndex)
    {
        //1.如果已经分割了四段，还没到末尾，说明这种分割方式不可能组成IP,剪枝返回
        if (path.size() == 4 && startIndex < s.size())
            return;
        //如果剩余的字符串分割完还不足4段，说明也不行，剪枝返回
        if (s.length() - startIndex + path.size() < 4)
            return;
        //分割成功，存储结果返回
        if (startIndex >= s.size() && path.size() == 4)
        {
            string tmp = path[0];
            for (int i = 1; i < path.size(); ++i)
            {
                tmp += "." + path[i];
            }
            result.push_back(tmp);
            return;
        }
        //2.递归分割字符串，每层递归分别分割1-3位，判断是回文子串存储；不是回文继续向后遍历
        for (int i = startIndex; i < startIndex + 3; i++)
        {
            string str = s.substr(startIndex, i - startIndex + 1);
            if (isIpNum(str))
            {
                path.push_back(str);
            } else
                continue;
            backtracking(s, i + 1); // 寻找i+1为起始位置的子串
            //3.回溯过程，弹出本次已经添加的子串
            path.pop_back();
        }

    }

    //判断是否为一个合法的ip数字（0-255）
    bool isIpNum(const string &s)
    {
        if (s.length() > 1 && s[0] == '0')
            return false;
        int ipNum = stoi(s);
        if (ipNum >= 0 && ipNum <= 255)
            return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
