#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0)
        return 0;
        if(s[0]=='0') return 0;
        int a,b;
        int prv=1, cur=1;
        for(int i=1;i<n;i++)
        {
            a=s[i]-'0';
            b=a+(s[i-1]-'0')*10;
            if(b<10 || b>=27)
            {
                if(a==0) return 0;
                    prv=cur;
            }
            else if(b==10 || b==20)
            {
                int tmp=cur;
                cur=prv;
                prv=tmp;
            }
            else if(b>10 && b<27 && b!=20)
            {
                int tmp = cur+prv;
                prv=cur;
                cur=tmp;
            } 
        }
        return cur;
    }
};
int main()
{
    Solution so;
    string s="1123";
    cout<<so.numDecodings(s)<<endl;
}