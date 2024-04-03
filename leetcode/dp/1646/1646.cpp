#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaximumGenerated(int n) {
        int ans=0;
        int flag=1;
        int a=0,b=1;
        for(int i=2;i<n;i++)
        {
            if(flag)
            {
                ans = a+b;
                flag --;
                a=b;
            }
            else
            {
                ans = 2*b;
                flag ++;
                b=ans;
            }
            cout<<ans<<" ";
        }
    }
};
int main()
{
    Solution so;
    cout<<so.getMaximumGenerated(7)<<endl;
}