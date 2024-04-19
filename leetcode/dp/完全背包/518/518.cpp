#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount < 0) return 0;
        vector<int> dp(amount+1, 0); // 总钱数为j时，有dp[j]种方法
        int n = coins.size();
        dp[0] = 1; // 初始化
        for (int i = 0;i < n;i++)
            for (int j = coins[i];j <= amount;j++)
                dp[j] += dp[j - coins[i]]; // dp[1] += dp[1-1]
        return dp[amount];
    }
};
int main()
{
    Solution so;
    int amount=5;
    vector<int> coins = {1,2,5};
    cout<<so.change(amount, coins)<<endl;
    return 0;
}