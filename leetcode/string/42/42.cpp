#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& height) {
        
        int n = height.size( );
        if (n < 3)return 0;

        vector<int> top;
        top.push_back(0);
        for(int i=1;i<n-1;i++)
        {
            if(height[i]>=height[i-1] && height[i]>=height[i+1])
                top.push_back(i);
        }
        top.push_back(n-1);

        n=top.size();
        int sum=0;
        pair<int, int> tmax{{top[0]},{height[top[0]]}};
        for(int i=1;i<n;i++)
        {
            if(height[top[i]] > tmax.second)
            {   
                int level = tmax.second;
                for(int j=tmax.first+1; j<top[i]; j++)
                    sum+=level-height[j];
            }
        }
        tmax={{top[n-1]},{height[top[n-1]]}};
        for (int i = n - 2;i >= 0;i--)
        {
            if(height[top[i]] > tmax.second)
            {   
                int level = tmax.second;
                for(int j=top[i]+1; j<tmax.first; j++)
                    sum+=level-height[j];
            }
        }
        return sum;
    }
};
int main()
{
    Solution so;
    vector<int> nums{2,0,0,1,4};
    cout<< so.canJump(nums) << endl;
}
