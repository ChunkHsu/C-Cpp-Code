#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
// 返回所有和为 0 且不重复的三元组
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size( );
        vector<vector<int>> ans;
        if (n < 3)
            return ans;
        sort(nums.begin( ), nums.end( ));
        int i = 0;
        while (i<n-2)
        {
            while (i > 0 && nums[i] == nums[i - 1])i++;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ans.push_back({ nums[i], nums[j], nums[k] });
                    j++;
                    while (j < k && nums[j] == nums[j + 1])j++;
                    while (j < k && nums[k] == nums[k - 1])k--;
                }
                else if (sum < 0)
                {
                    j++;
                    while (j < k && nums[j] == nums[j + 1])j++;
                }
                else
                {
                    k--;
                    while (j < k && nums[k] == nums[k - 1])k--;
                }
            }
            i++;
        }
        return ans;
    }
};
int main( )
{
    Solution so;
    // -1,0,1,2,-1,-4
    // -4 -1 -1 0 1 2
    // [[-1,-1,2],[-1,0,1]]
    vector<int> v = { -1,0,1,2,-1,-4 };
    auto ans = so.threeSum(v);
    for (int i = 0;i < ans.size( );i++)
    {
        for (int j = 0;j < ans[i].size( );j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

}