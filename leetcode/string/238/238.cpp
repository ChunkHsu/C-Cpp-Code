#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        if(n==1)return ans;
        
        ans[n-1] = 1;                   // ans[i] 表示右侧的乘积
        for(int i=n-2;i>=0;i--)         // 倒叙遍历，计算右侧乘积
            ans[i] = nums[i+1]*ans[i+1];
        
        int tmp = 1;                    // tmp为左侧乘积
        for(int i=1; i<n; i++)          // 顺序遍历，计算左侧乘积
        {
            tmp *= nums[i-1];           // tmp为左侧乘积
            ans[i] = tmp*ans[i];        // ans = 左 * 右
        }
            
        return ans;
    }
};

int main( )
{
    Solution so;
    vector<int> ans{ 1,2,3,4 };
    for (auto &p : so.productExceptSelf(ans))
        cout << p <<" ";
}