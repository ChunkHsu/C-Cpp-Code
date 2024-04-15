#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prv = 0, cur = 0, tmp = 0;
        for (int i = 2;i <= n;i++)
        {
            tmp = min(cur + cost[i - 1], prv + cost[i - 2]);
            prv = cur;
            cur = tmp;
        }
        return cur;
    }
};
int main( )
{
    Solution so;
    vector<int> cost{ 10,15,0 };
    cout << so.minCostClimbingStairs(cost) << endl;
    return 0;
}