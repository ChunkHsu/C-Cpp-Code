#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 二分
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size( );
        if (!n)return 0;
        vector<int> order;
        order.push_back(nums[0]);
        for(int i:nums)
        {
            if(i>order.back())
                order.push_back(i);
            else
            {
                vector<int>::iterator it = lower_bound(order.begin(), order.end(), i);
                *it = i;
            }
        }
        return order.size();
    }
    int lengthOfLIS2(vector<int> &nums)
    {
        int n=nums.size();
        if(n==0)return 0;
        vector<int> ans(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<ans.size();j++)
            {
                if(nums[i]>nums[j])
                {
                    ans[i]=max(ans[j]+1, ans[i]); 
                }
            }
        }
        return ans[n-1];
    }
};
int main( )
{
    Solution so;
    vector<int> nums={10,9,2,5,3,7,101,18};
    // vector<int> nums={7,7,7,7,7}; 
    cout<<so.lengthOfLIS2(nums)<<endl;
    return 0;
}
