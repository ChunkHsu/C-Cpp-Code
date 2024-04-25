#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if (target < 0)return 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int j = 0;j <= target;j++)
            for (int i = 0;i < n;i++)
                if (j >= nums[i])
                    dp[j] += dp[j - nums[i]];
        return dp[target];
    }
};
int main()
{
    Solution so;
    vector<int> nums = {1,2,3};
    int target=4;
    cout << so.combinationSum4(nums, target) << endl;
    return 0;
}