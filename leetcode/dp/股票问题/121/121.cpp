#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // 贪心
    int maxProfit(vector<int>& prices)
    {
        int minp, prv;
        int n = prices.size();
        if (!n)return 0;
        minp = prices[0];
        prv = 0;
        for (int i : prices) {
            if (i > minp)
                prv = max(prv, i - minp);
            else
                minp = i;
        }
        return prv;
    }
    // 动态规划
    int maxProfit2(vector<int>& prices)
    {
        int n = prices.size();
        if (!n)return 0;
        vector<vector<int>> dp(2, vector<int>(n, 0)); // dp[1][i] 表示持有股票的最大值， dp[0][i] 表示不持有股票的最大值
        dp[0][0] = 0;
        dp[1][0] = -prices[0];
        for (int i = 1;i < n;i++) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] + prices[i]); // 今天不持有股票的最大值为 = max(昨天不持有的最大值，昨天持有的 + 今天卖出去的)
            dp[1][i] = max(dp[1][i - 1], -prices[i]); // 今天持有股票的最大值为 = max(昨天持有的最大值， 今天刚买入持有的最大值)
        }
        return dp[0][n - 1];
    }
};
int main()
{
    Solution so;
    vector<int> prices = { 2,1 };
    cout << so.maxProfit(prices) << endl;
    return 0;
}