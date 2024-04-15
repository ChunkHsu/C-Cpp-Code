//https://leetcode.cn/problems/maximum-subarray/solutions/9058/dong-tai-gui-hua-fen-zhi-fa-python-dai-ma-java-dai/?envType=list&envId=xKWYGX7b
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size( );
        if (!n)return 0;
        int cur = nums[0];
        int ans = cur;
        for (int i = 1;i < n;i++)
        {// 如果前缀和不大于0，说明前面的已经正负抵消了，所以最大的子段应新开一个，负数+负数越来越小。
            if (cur > 0) 
                cur += nums[i];
            else
                cur = nums[i];
            ans = max(ans, cur);
        }
        return ans;
    }
};
int main( )
{
    Solution so;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << so.maxSubArray(nums) << endl;
    return 0;
}