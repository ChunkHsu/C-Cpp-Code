#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int> &nums)
    {
        /*  1   2   3
        0   0   0   0
            1   1   1
                2   2
                3   3
                    4
                    5
                    6
        */
        int n = nums.size();
        unordered_map<int, int> dp; // 存储计算得到的每个和
        stack<int> tmp; // 存放已经计算的和
        dp[0] = 0;

        int sum = 0;
        for (int i = 0;i < n;i++)
            sum += nums[i];

        if (sum % 2)return false;

        sum /= 2;

        for (int i = 0;i < n;i++) {
            for (auto d : dp) { // 根据已经计算的和计算新的和
                int t = d.first + nums[i];
                if (t == sum)return true; // 和为sum的一半返回true
                else tmp.push(t); // 计算新的和
            }
            while (!tmp.empty( )) { // 新计算的和入集合
                dp[tmp.top( )] = 1;
                tmp.pop( );
            }
        }
        return false;
    }
    bool canPartition2(vector<int> &nums)
    {
        int n = nums.size( );
        int sum = 0;
        for (int i : nums)
            sum += i;

        if (sum % 2)return false;
        int t = sum / 2;
        vector<int> dp(t + 1, 0); // 容量为j时，能装入的元素和为dp[j]
        // 每个元素是一个物品，占用空间为元素数值，值为数值
        // 如果有负数，需要初始化为 INT_MIN 

        for (int i = 0;i < n;i++)
            for (int j = t;j >= nums[i];j--)
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);

        if (dp[t] == t) // 如果背包被装满
            return true;
        return false;
    }
};
int main( )
{
    Solution so;
    vector<int> nums = { 2,2,1,1 };
    cout << so.canPartition2(nums) << endl;
}
