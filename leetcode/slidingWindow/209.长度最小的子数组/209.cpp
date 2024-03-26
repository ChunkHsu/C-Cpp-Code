#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size( );
        if (n == 0)return 0;
        int ans = INT_MAX;
        int i = 0, j = 0;
        int sum = 0;
        while (i < n)
        {
            sum += nums[i];
            while (sum >= target)
            {
                ans = min(i - j + 1, ans);
                sum -= nums[j];
                j++;
            }
            i++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
int main( )
{
    Solution so;
    vector<int> nums = {2,3,1,2,4,3};
    cout<<so.minSubArrayLen(7, nums);
}