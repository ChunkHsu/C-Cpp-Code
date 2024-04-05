#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j = 0; j<nums.size(); j++)
            if(nums[j] != nums[i])
                nums[++i] = nums[j]; 
        return i+1;
    }
};

int main()
{
    Solution so;
    vector <int> nums= {1,1,2};
    cout<< so.removeDuplicates(nums) <<endl;    
}