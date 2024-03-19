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
        vector<int> new_n(n,0);
        for(int i=0; i<n; i++)
            new_n[(i+k)%n] = nums[i];
        nums = new_n;
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