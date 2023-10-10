//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
//
// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。 
//
// 
//
// 示例 1: 
//
// 
//输入: num1 = "2", num2 = "3"
//输出: "6" 
//
// 示例 2: 
//
// 
//输入: num1 = "123", num2 = "456"
//输出: "56088" 
//
// 
//
// 提示： 
//
// 
// 1 <= num1.length, num2.length <= 200 
// num1 和 num2 只能由数字组成。 
// num1 和 num2 都不包含任何前导零，除了数字0本身。 
// 
//
// Related Topics 数学 字符串 模拟 👍 1216 👎 0

#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if(num1[0]=='0' || num2[0]=='0')
            return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = num1.length();
        int m = num2.length();
        vector<int> a(n);
        vector<int> b(m);
        vector<int> c(m + n, 0);


        string result;
        for (int i = 0; i < n; i++)
        {
            a[i] = num1[i] - '0';
        }
        for (int i = 0; i < m; i++)
        {
            b[i] = num2[i] - '0';
        }

        for (int i = 0; i <= n + m - 2; i++)
        {
            int Ci = 0;
            for (int j = 0; j <= i; j++)
            {
                if (j < n && i - j < m)
                {
                    Ci += a[j] * b[i - j];
                }
            }

            int carry = 0;
            int k = i;
            while (Ci)
            {
                int x = Ci % 10;
                int temp = (c[k] + x + carry) / 10;
                c[k] = (c[k] + x + carry) % 10;
                carry = temp;
                k++;
                Ci = Ci / 10;
            }
            if(carry!=0)
                c[k]+=carry;


        }
        //c[n+m-1]+=carry;
        for (int i = n + m - 1; i >= 0; i--)
        {
            char ch = c[i] + '0';
            result += ch;
        }
        int count=0;
        while(result[count]=='0')
        {
            count++;
        }
        return result.substr(count,result.length());
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main()
{

    Solution *s = new Solution();
    s->multiply("2925", "4787");
}