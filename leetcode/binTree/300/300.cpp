#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
    // 动态规划
    int lengthOfLIS(vector<int> nums)
    {
        int n=nums.size();
        if(n==0)
            return 0;
        int ans=0;
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> nums{10,9,2,5,3,7,101,18};
    Solution so;
    cout<<so.lengthOfLIS(nums)<<endl;
}
