#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i: nums)
            sum+=i;
        int left=0,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                left+=nums[i-1];
            if(left==sum-left-nums[i])
                return i;
        }
        return -1;
    }
};
int main()
{
    
}