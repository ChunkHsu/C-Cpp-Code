#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec={2,4,1};
    int mmax,mmin,ans=0;
    mmin=vec[0];
    int n=vec.size();
    /*假设每次最少买入, 每天计算与最少差值的最大值*/
    for(int i=1;i<n;i++)
    {
        if(vec[i]<mmin)
            mmin=vec[i];
        ans=max(ans, vec[i]-mmin);
    }
    cout<<ans<<endl;
}