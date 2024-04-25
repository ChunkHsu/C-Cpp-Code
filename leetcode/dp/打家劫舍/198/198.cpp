#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (!n)
            return 0;

        vector<int> dp(n + 1, 0); // 第 i 天偷的最多的钱为 dp[i]
        dp[1] = nums[0];

        for (int i = 1;i < n;i++)
            dp[i + 1] = max(dp[i], dp[i - 1] + nums[i]);

        return dp[n];
    }
};
int main()
{
    Solution so;
    vector<int> nums = { 1,2 };
    cout << so.rob(nums) << endl;
    return 0;
}