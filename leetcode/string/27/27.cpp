#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:

    int removeElement(vector<int> &nums, int val)
    {
        int index = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != val)
                nums[index++] = nums[i];
        }
        return index;
    }

    int removeElement2(vector<int> &nums, int val)
    {
        int len = nums.size();
        int ans = 0;
        for(int i=0;i<len;i++)
        {   
            if(nums[i] == val)
            {
                ans ++;
                nums[i] = nums[len-1];
                len--;
                i--;
            }
        }
        return nums.size() - ans;
    }
};

int main()
{
    Solution so;
    vector<int> nums={3,2 , 2, 3};
    int val = 3;
    int index = so.removeElement2(nums, val);
    for(int i =0; i< index; i++)
        cout<< nums[i] <<" ";
    cout<< endl << index <<endl;
}