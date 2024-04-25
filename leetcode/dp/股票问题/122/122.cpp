#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        // 有的赚就卖，并且当天也买
        int minp = INT_MAX; // 股票最低价
        int res = 0; // 营收总额
        for (int i : prices) {
            if (i < minp) { // 如果今天价格比昨天低，就更新最低价
                minp = i;
            }
            else {
                res += i - minp; // 否则就卖出，并且今天也买入，更新最低价
                minp = i;
            }
        }
        return res;
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
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] - prices[i]); // 今天持有股票的最大值为 = max(昨天持有的最大值， 昨天不持有的最大值 - 今天刚买入持有的最大值)
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