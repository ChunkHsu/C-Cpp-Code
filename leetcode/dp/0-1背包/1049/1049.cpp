#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int n = stones.size( );
        int sum = 0;

        for (int i = 0;i < n;i++)
            sum += stones[i]; // 每块石头占空间为其值大小
        // 计算背包总容量

        int t = sum / 2; // 将空间一分为二，求一半空间内能放的石头的最大重量
        vector<int> dp(t + 1); // 背包容量为 j 时， 石头的最大重量

        for (int i = 0;i < n;i++)
            for (int j = t;j >= stones[i];j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);

        return sum - dp[t] - dp[t]; // 大的一半去抵消小的一半，剩余的即是最小的。
    }
};
int main( )
{
    Solution so;
    vector<int> stones = { 2, 7 , 4, 1, 8, 1 };
    cout << so.lastStoneWeightII(stones) << endl;
    return 0;
}