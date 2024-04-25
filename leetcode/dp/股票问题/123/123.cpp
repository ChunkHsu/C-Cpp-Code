#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if (!n)return 0;
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        dp[0][1] = -prices[0];  // 第一次持有
        dp[0][2] = 0;           // 第一次不持有
        dp[0][3] = -prices[0];  // 第二次持有
        dp[0][4] = 0;           // 第二次不持有

        for (int i = 1;i < n;i++) {
            dp[i][1] = max(dp[i - 1][1], -prices[i]);               // 第1次 持有 = （前一天持有， 第一次持有）
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); // 第1次不持有 = （前一天不持有， 前一天持有 + 今天卖出）
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]); // 第2次持有 = （前一天第二次持有， 前一天第二次不持有 - 今天买入）
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]); // 第2次不持有 = （前一天第二次不持有， 前一天第二次持有 + 今天卖出）
        }
        return dp[n - 1][4];
    }
};
int main()
{
    Solution so;
    vector<int> prices = { 2,1 };
    cout << so.maxProfit(prices) << endl;
    return 0;
}