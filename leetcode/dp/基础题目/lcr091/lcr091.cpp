#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size( );
        vector<int> ret(3);
        vector<int> ans(3);
        ret = costs[0];
        for (int i = 1;i < n;i++)
        {   //当前房子的第j号颜料cost + 前面一个的其余两个颜料中最小的cost
            ans[0] = costs[i][0] + min(ret[1], ret[2]); 
            ans[1] = costs[i][1] + min(ret[0], ret[2]);
            ans[2] = costs[i][2] + min(ret[0], ret[1]);
            ret = ans;
        }
        return *min_element(ret.begin(),ret.end());
    }
};
int main( )
{
    Solution so;
    vector<vector<int>> costs = { {16,16,5},{22,22,1} };
    // vector<vector<int>> costs ={{1,16,18},{17,1,6},{10,1,18},{12,19,5},{18,11,6},{11,9,6},{18,10,10},{18,13,18},{1,17,9},{7,19,15},{10,20,11},{17,12,2},{11,6,12},{7,18,2},{14,20,12},{13,5,10},{13,20,14},{8,9,2},{14,15,19}};
    cout << so.minCost(costs) << endl;
}
