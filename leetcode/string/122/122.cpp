#include<iostream>
#include<vector>
// prices = [7,1,5,3,6,4]
// 输出：7
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans=0;
        int n=prices.size();
        int minp = prices[0];
        int prof = 0;
        for(int i = 1; i<n; i++)
        {   /*上升期买最低价*/
            /*下降期统计收入*/
            if(prices[i]<prices[i-1])
            {
                prof = prices[i-1]-minp;
                ans += prof;
                minp = prices[i];
            }
        } 
        /*最后一期收入*/
        ans += prices[n-1] - minp;
        return ans;
    }
};
int main()
{ 
    Solution so;
    vector<int> nums={7,1,5,3,6,4};
    cout<<so.maxProfit(nums)<<endl;
}