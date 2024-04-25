#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n = prices.size();
        if (k > n)
            k = n;

        vector<vector<int>> dp(n, vector<int>(k * 2 + 1, 0));
        for (int i = 0;i < k * 2 + 1;i++) {
            if (i % 2)
                dp[0][i] = -prices[0];
        }

        for (int i = 1;i < n;i++) {
            for (int j = 1;j < k * 2 + 1;j++) {
                if (j % 2)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]); // 持有
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]); // 不持有
            }
        }

        return dp[n - 1][2 * k];
    }
};
int main()
{
    Solution so;
    int k = 2;
    vector<int> prices = { 2,4,1 };
    cout << so.maxProfit(k, prices) << endl;
    return 0;
}