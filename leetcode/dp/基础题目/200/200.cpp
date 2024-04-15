#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


//1 <= nums.length <= 2500
//-104 <= nums[i] <= 104

class Solution {

    vector<int> mem;
    int len_i(vector<int> &nums,int index, int n)
    {
        if(mem[index]!=-1)
            return mem[index];

        if(index==n-1){
            mem[index] = 1;
            return 1;
        }
            
        int max_l=1;
        for(int j=index+1; j<n; j++)
            if(nums[index]<nums[j])
                max_l=max(max_l, len_i(nums, j, n)+1);
        mem[index]=max_l;
        return max_l;
    }
public:
    Solution():mem(2501, 1){}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        if(n<2) return n;
        for(int i=0; i<n; i++)
        {
            int tmp = len_i(nums, i, n);
            if(tmp>ans)
                ans = tmp;
        }
        return ans;
    }
    int lengthOfLIS2(vector<int>& nums)
    {
        int n=nums.size();
        for(int i=n-1; i>=0; i--)
        {
            if(i==n-1) {mem[i]=1; continue;}
            for(int j=i+1; j<n; j++)
            {
                if(nums[j]>nums[i])
                {
                    mem[i]=max(mem[j]+1, mem[i]);
                }
            }
        }
        return *max_element(mem.begin(),mem.begin()+n);
    }

    int lengthOfLIS3(vector<int> &nums)
    {
        vector<int> d{nums[0]};
        int n =nums.size();
        for(int i=1; i<n; i++)
        {
            if(nums[i]>d.back())
                d.push_back(nums[i]);
            else
            {// lower_bound 二分查找：返回 >= 给定值的第一个元素的位置
                auto p = lower_bound(d.begin(), d.end(), nums[i]);
                *p = nums[i];
            }
        }
        return d.size();
    }
};

int main()
{
    Solution so;
    vector<int> nums={4,10,4,3,8,9};
    cout<< so.lengthOfLIS3(nums)<< endl;
    return 0;
}