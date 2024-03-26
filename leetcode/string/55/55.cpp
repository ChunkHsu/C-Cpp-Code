#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return true;
        int minstep=n-1; 
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]+i>=minstep)
                minstep=i;
        }
        return !minstep;
    }
};
int main()
{
    Solution so;
    vector<int> nums{2,0,0,1,4};
    cout<< so.canJump(nums) << endl;
}
