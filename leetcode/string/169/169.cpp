// 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
/*示例 1：
输入：nums = [3,2,3]
输出：3

示例 2：
输入：nums = [2,2,1,1,1,2,2]
输出：2
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> nums_sum;
        int ans[2]={0,0}, n=nums.size();
        int k = n/2;
        for(int i=0; i<n; i++)
            nums_sum[nums[i]]++;
        for(auto &pair : nums_sum)
        {
            int key = pair.first;
            int val = pair.second;
            if(val >= k && val > ans[1])
            {
                ans[0] = key;
                ans[1] = val;
            }
        }
        return ans[0];
    }

    int majorityElement2(vector<int>& nums)
    {
        int vote = 0;
        int ans;
        for(auto & num : nums)
        {
            if(!vote)
                ans = num;
            if(ans == num)
                vote++;
            else    
                vote--;
        }
        return ans;
    }
};

int main()
{
    Solution so;
    vector<int> nums = {2,2,1,1,1,2,2};
    cout<<so.majorityElement2(nums)<<endl;
}
