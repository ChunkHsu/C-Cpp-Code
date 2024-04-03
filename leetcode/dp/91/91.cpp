#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s)
    {
        int n = s.size( );
        if (n == 0) return 0;
        if (n == 1)
        {
            if (s[0] != '0')
                return 1;
            else
                return 0;
        }
        
        int pre = 1, cur = 0;
        if (s[0] == '0')
            return 0;

        if ((s[0] == '1' && s[1] != '0') || (s[0] == '2' && s[1] < '7'))
            cur = 2;
        else if (s[0] == '0' || (s[1] == '0' && s[0] != '1' && s[0] != '2'))
            return 0;
        else
            cur = 1;
        
        for (int i = 2;i < n;i++)
        {
            if (s[i] != '0')
            {
                if ((s[i - 1] == '1') || (s[i - 1] == '2' && s[i] < '7'))
                {
                    int tmp = cur + pre;
                    pre = cur;
                    cur = tmp;
                }
            }
            else
            {
                if (s[i - 1] != '1' && s[i - 1] != '2')
                    return 0;
                cur--;
            }
        }
        
        return cur;
    }
};
int main( )
{
    Solution so;
    string s = "123123";
    cout << so.numDecodings(s) << endl;
}