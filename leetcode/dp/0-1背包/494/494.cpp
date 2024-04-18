#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size( );
        int sum = 0;
        for (int i = 0;i < n;i++)
            sum += nums[i];

        sum += target;
        if (sum < 0)return 0;
        if (sum % 2)return 0;
        int t = sum / 2;

        vector<int> dp(t + 1, 0);
        dp[0] = 1;

        for (int i = 0;i < n;i++)
            for (int j = t;j >= nums[i];j--)
                dp[j] += dp[j - nums[i]];

        return dp[t];
    }
    int findTargetSumWays2(vector<int>& nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0;i < n;i++)
            sum += nums[i];
        sum += target;

        if (sum < 0)return 0;
        if (sum % 2)return 0;
        int t = sum / 2;

        vector<int> dp(t + 1, 0); // dp[j] ,使得背包容量为j的方法为dp[j]种
        dp[0] = 1;

        for (int i = 0;i < n;i++)
            for (int j = t;j >= nums[i];j--)
                dp[j] += dp[j - nums[i]];
            
        return dp[t];
    }
};
int main( )
{
    Solution so;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << so.findTargetSumWays2(nums, target) << endl;
}