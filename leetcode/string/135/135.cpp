#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings) {   
        int n=ratings.size();
        vector<int> ans(n, 1);
        int left=1;
        int right=1;
        for(int i=1;i<n;i++)
        {
            int j=n-1-i;
            if(ratings[i]>ratings[i-1])
            {
                left++;
                ans[i]=max(ans[i], left);
            }
            else
                left=1;
            
            if(ratings[j]>ratings[j+1])
            {   
                right++;
                ans[j]=max(ans[j], right);
            }
            else
                right=1;
        }
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=ans[i];
        return sum;
    }
};
int main( )
{
    Solution so;
    vector<int> nums{ 0,1,2,5,3,2,7 };
    cout<< so.candy(nums);

}
