#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> f (nums.end()-k, nums.end());
        f.insert(f.end(),nums.begin(), nums.end()-k);
        nums = f;
    }
    void rotate2(vector<int> & nums, int k)
    {
        int n = nums.size();
        k %= n;
        for(int i=n-k; i<n; i++)
        {   
            int tmp = nums[i];
            int start = (i+k)%n;    
            for(int j=i-1; j>=start; j--)
                nums[j+1] = nums[j];
            nums[start] = tmp;
        }
    }
};

int main()
{
    Solution so;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    so.rotate2(nums, k);
    for(auto &p: nums)
        cout<< p << " ";
    cout << endl;
}