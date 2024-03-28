#include<bits/stdc++.h>
using namespace std;
class Solution {
    int find_max(vector<int>::const_iterator begin, vector<int>::const_iterator end)
    {
        int prv=0, cur=0;
        for(vector<int>::const_iterator it=begin; it!=end;it++ )
        {
            int tmp = max(cur, prv+*it);
            prv=cur;
            cur=tmp;
        }
        return cur;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        int n1 = find_max(nums.begin(), nums.begin()+n-1);
        int n2 = find_max(nums.begin()+1, nums.end());
        return max(n1,n2);
    }
};
int main()
{
    Solution so;
    vector<int> nums={2};
    cout<<so.rob(nums)<<endl;
}