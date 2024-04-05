#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
        int jump(vector<int>& nums) {
        int n=nums.size();
        // 边界值
        if(n<2)return 0;

        // max1 记录当前一步能够跳的最远距离
        // max2 记录下一步能够跳的最远距离
        int max1=nums[0],max2=0; // 初始值最远为第一个格子的距离
        vector<int> dp(n,0); // dp[i]为到当前格子的最少步数
        dp[0]=1;

        for(int i=1;i<n;i++)
        {
            // 如果当前一步能够压线到该格子
            if(max1>=i)
            {   
                dp[i]=dp[i-1]; // 更新到该格子的step
            }
            // 如果当前一步不能到该格子
            else
            {
                dp[i]=dp[i-1]+1; // 需要多跳一步
                max1=max2; // 更新当前步的最远距离    
            }
            max2=max(max2, nums[i]+i); // 更新下一步的最远距离
        }
        return dp[n-1]; // 返回最少的步数
    }
};

int main()
{
    Solution so;
    vector<int> nums{1,1,2,1,1};
    cout<<so.jump(nums)<<endl;
}