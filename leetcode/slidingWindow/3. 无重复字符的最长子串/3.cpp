#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size( );
        if (n < 2)return n;
        int i = 0, j = 0;
        int ans = 0;
        bool flag[256];
        for (int i = 0;i < 256;i++)
            flag[i] = 0;
        
        while (i < n)
        {
            if (!flag[s[i]])
            {
                ans = max(i - j + 1, ans);
                flag[s[i]] = 1;
            }
            else
            {
                while (s[i] != s[j]) flag[s[j++]]=0;
                j++;
                ans = max(i - j + 1, ans);
            }
            i++;
        }
        return ans;
    }
};
int main( )
{
    //"abcabcbb" 3
    //"pwwkew" 3
    Solution so;
    string s = "    ";
    cout << so.lengthOfLongestSubstring( s);
}