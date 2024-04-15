#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0); // 区间长度为i的dp[i]种不同的二叉搜索的种数,
        // 如 dp[3] 可以是 1,2,3 的二叉搜索树，也可以是 2,3,4 的搜索树的种数
        dp[0] = 1;

        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= i;j++)
                dp[i] += dp[j - 1] * dp[i - j];

        return dp[n];
    }
};
int main( )
{
    Solution so;
    cout << so.numTrees(5) << endl;
}