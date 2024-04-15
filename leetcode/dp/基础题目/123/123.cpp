
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        if(n<2)return 0;
        
        int min1,min2;
        int ans=0;
        vector<int> dp1(n,0),dp2(n,0);
        //两次购买股票，可以对序列进行划分，划分成两段，即[0 ~ i]和[i ~ n-1]，预处理出每个区间的最大值，
        //dp1[i]表示前i个位置的最大值，
        min1=prices[0];
        for(int i=1;i<n;i++)
        {
            min1=min(min1,prices[i]);
            dp1[i]=max(prices[i]-min1, dp1[i-1]);
        }
        //dp2[i]表示后n-i个位置的最大值
        min2=prices[n-1];
        for(int i=n-2;i>=1;i--)
        {
            min2=max(min2,prices[i]);
            dp2[i]=max(dp2[i+1],min2-prices[i]);
        }
        //最后再遍历一次序列，将[0 ~ i]和[i ~ n-1]的最大值相加，取每个可能的和的最大值
        for(int i=0;i<n;i++)
        {
            //之所以相交是因为可以只购买一次 如 1,2,3,4,5
            ans=max(dp1[i]+dp2[i], ans);
        }
        return ans;
    }
};

int main()
{
    Solution so;
    vector<int> nums{1,2,3,4,5};
    cout<<so.maxProfit(nums)<<endl;
}