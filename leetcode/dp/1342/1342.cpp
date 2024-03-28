#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0)return 0;
        int ans=0;
        while(num!=0)
        {
            if(num%2==0)
                num=num/2;
            else
                num--;
            ans++;
        }
        return ans;
    }
    int numberOfSteps2(int num) {
        vector<int> f(num+1,0);
        f[0]=0;
        f[1]=1;
        for(int i=2;i<=num;i++)
        {
            if(i%2)
                f[i]=f[i-1]+1;
            else
                f[i]=f[i/2]+1;
        }
        return f[num];
    }
};
int main()
{
    Solution so;
    int n =123;
    cout<<so.numberOfSteps2(n)<<endl;
}