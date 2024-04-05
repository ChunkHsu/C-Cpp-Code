#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool comp(int &a, int &b)
{
    return a>b;
}

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans=0;
        int n=prices.size();
        if(n<=2)
            return ans;
        int minp = prices[0];
        vector<int> prof;
        for(int i=1; i<n; i++)
        {
            if(prices[i]<prices[i-1])
            {
                prof.push_back(prices[i-1]-minp);
                minp = prices[i];
            }
        }
        prof.push_back(prices[n-1]-minp);
        sort(prof.begin(), prof.end(), comp);
        if(prof.size()<2)
            ans = prof[0];
        else
            ans = prof[0]+prof[1];
        for(auto &p: prof)
            cout<<p<<" ";
        cout<<endl;
        return ans;
    }
    int maxProfit2(vector<int> &prices)
    {
        int ans=0;
        int n=prices.size();
        if(n<=2)
            return ans;
        vector<int> maxp{prices[0]}; // 最大价格
        vector<int> minp{prices[0]}; // 最小价格
        int pt=0;
        int op0=0;
        for(int i=1; i<n; i++)
        {//{1,2,4,3,2,5,7,2,4,9,0}
            int op1=prices[i]-prices[i-1];
            if(abs(op0) + abs(op1) < abs(op0+op1))//异号
            {
                pt++;
                minp.push_back(0);
                maxp.push_back(0);
            }
            op0=op1;
            //下降
            if(prices[i]<prices[i-1])
            {
                minp[pt] = prices[i];
            }
            //上升
            if(prices[i]>prices[i-1])
            {
                maxp[pt] = prices[i];
            }
        }
        for(auto &p: maxp)
            cout<<p<<" ";
        cout<<endl;
        for(auto &p: minp)
            cout<<p<<" ";
        cout<<endl;
        return ans;
    }
};

int main()
{
    Solution so;
    vector<int> prices={1,2,4,2,5,7,2,4,9,0}; // 13
    cout<< so.maxProfit2(prices) << endl;
}