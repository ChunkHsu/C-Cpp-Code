#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size( );
        
        vector<string>::iterator it = min_element(
            strs.begin( ), strs.end( ),
            [ ](const string &s1, const string &s2)
            {
                return s1.size( ) < s2.size( );
            }
        );

        int len_min = it->size( );
        int index = distance(strs.begin( ), it);

        for (int i = 0;i < n;i++)
        {
            int n_of = strs[i].size( );
            if (n_of < len_min)
            {
                len_min = n_of;
                index = i;
            }
        }
        int short_n = strs[index].size( );
        int t = 0;
        while (t < short_n)
        {
            for (int i = 0;i < n;i++)
            {
                if (strs[i][t] != strs[index][t])
                    return ans;
            }
            ans += strs[index][t++];
        }
        return ans;
    }
};
int main( )
{
    Solution so;
    vector<string> strs = { "flower","flower","flgh" };
    cout << so.longestCommonPrefix(strs);
}