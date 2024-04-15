#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(!n)return 0;
        vector<pair<int,int>>ans(n+1,make_pair(0,INT_MIN));
        vector<int>dp(n+1,1);
        int max_l=1;
        ans[0].first=1,ans[1].first=1,ans[1].second=nums[0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    dp[i]=dp[j]+1;
                max_l=max(dp[i],max_l);
            }
            if(ans[dp[i]].first)
            {
                if(nums[i]>=ans[dp[i]].second)
                {
                    ans[dp[i]].second=nums[i];
                    ans[dp[i]].first++;
                }
            }
            else
                ans[dp[i]].first+=ans[dp[i]-1].first;
            cout<<max_l<<endl;
            for(int t=1;t<=n;t++)
            {
                cout<<ans[t].first<<" ";
            }
            cout<<endl;
            for(int t=1;t<=n;t++)
            {
                cout<<ans[t].second<<" ";
            }
            cout<<endl;
        }
        return ans[max_l].first; 
    }
};
int main()
{
    Solution so;
    vector<int> nums={3,1,2};
    cout<<so.findNumberOfLIS(nums)<<endl;
    return 0;
}