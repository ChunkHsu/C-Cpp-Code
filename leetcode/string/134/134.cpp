#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size( );
        if(n==0)return -1;
        int res = 0;
        int i = 0;
        while (i < n)
        {
            int ii = 0;
            res = 0;
            while (ii < n)
            {
                int ri = (i + ii) % n;
                res += gas[ri] - cost[ri];
                //不够
                if (res < 0)
                {
                    i = i + ii + 1;
                    break;
                }
                ii++;
            }
            if (ii == n)
                return i;
        }
        return -1;
    }
};
int main( )
{
    Solution so;
    vector<int> gas{1,2,3,4,5}, cost{3, 4,5,1,2};
    // vector<int> gas{2,3,4}, cost{3, 4, 3};
    cout<< so.canCompleteCircuit(gas, cost);

}
