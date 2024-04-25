#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1,INT_MAX); // 容量为 j 时，最少的硬币个数为 dp[j] 个
        dp[0] = 0;

        for (int i = 0;i < n;i++)
            for (int j = coins[i];j <= amount;j++) {
                if (dp[j - coins[i]]!= INT_MAX) // 如果前一个状态无法到达，则下一个容量
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
                
        if (dp[amount] == INT_MAX)return -1;
        return dp[amount];
    }
};
int main()
{
    Solution so;
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << so.coinChange(coins, amount) << endl;
}