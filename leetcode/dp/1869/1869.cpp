#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkZeroOnes(string s) {
        int n=s.size();
        int one_prv=0, one_cur=0;
        int zero_prv=0,zero_cur=0;
        int max_one=0, max_zero=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                one_cur=one_prv+1;
                max_one=max(one_cur,max_one);
                one_prv=one_cur;
                zero_prv=0;
            }
            else
            {
                zero_cur=zero_prv+1;
                max_zero=max(zero_cur,max_zero);
                zero_prv=zero_cur;
                one_prv=0;
            }
        }
        if(max_one>max_zero)
            return true;
        return false;
    }
};
int main()
{
    Solution so;
    string s="111000";
    cout<<so.checkZeroOnes(s)<<endl;
}