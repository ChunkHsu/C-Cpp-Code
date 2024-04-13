#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int integerBreak(int n)
    {
        vector<int> dp(n + 1); // 为第i个数拆分后最大的乘积的值
        // 初始化数组为 0
        dp[1] = 0; // 为 1 的时候没有可分解的数字，所以为 0

        for (int i = 2;i <= n;i++) // 遍历顺序
            for (int j = 1;j < i;j++)
            {
                int tmp = max(j * (i - j), j * dp[i - j]); // 拆分或者未拆分
                dp[i] = max(tmp, dp[i]);
            }
                
        return dp[n];
    }
    vector<int> integerBreakPartition(int n) // 打印出划分的整数
    {
        vector<int> dp(n + 1); // 为第i个数拆分后最大的乘积的值
        vector<vector<int>> ans(n+1);
        // 初始化数组为 0
        dp[1] = 0; // 为 1 的时候没有可分解的数字，所以为 0

        for (int i = 2;i <= n;i++) // 遍历顺序
            for (int j = 1;j < i;j++)
            {
                int tmp = max(j * (i - j), j * dp[i - j]); // 拆分或者未拆分

                vector<int> cur;
                cur.push_back(j);
                if (j * (i - j) > j * dp[i - j])
                    cur.push_back(i - j);
                else
                    for(int t: ans[i-j])
                        cur.push_back(t);

                if (tmp > dp[i])
                    ans[i] = cur;
                dp[i] = max(tmp, dp[i]);
            }
                
        return ans[n];
    }
};
int main( )
{
    // 2 = 1 + 1 = 1 * 1 = 1
    // 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
    Solution so;
    cout << so.integerBreak(10) << endl;
    for (int i : so.integerBreakPartition(10))
        cout << i << " ";
    cout << endl;
    return 0;
}