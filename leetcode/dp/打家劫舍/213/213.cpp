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
        if (n == 1)
            return nums[0];

        int cur = 0, prv = 0, tmp;
        int ans1, ans2;
        for (int i = 0;i < n - 1;i++) {
            tmp = max(cur, prv + nums[i]);
            prv = cur;
            cur = tmp;
        }
        ans1 = cur;

        cur = 0; prv = 0;
        for (int i = 1;i < n;i++) {
            tmp = max(cur, prv + nums[i]);
            prv = cur;
            cur = tmp;
        }
        ans2 = cur;

        return max(ans1, ans2);
    }
};
int main()
{
    Solution so;
    vector<int> nums = { 5, 1 };
    cout << so.rob(nums) << endl;
    return 0;
}