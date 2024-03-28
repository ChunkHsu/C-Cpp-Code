#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n<2)return 0;
        vector<int> f(n+1,0);
        for(int i=2;i<n;i++)
        {
            f[i]=min(cost[i-1], cost[i-2]);
            cost[i]+=f[i];
        }
        f[n]=min(cost[n-1], cost[n-2]);
        return f[n];
    }
};
int main()
{
    vector<int> cost ={10, 15, 20};
    Solution so;
    cout<<so.minCostClimbingStairs(cost)<<endl;

}