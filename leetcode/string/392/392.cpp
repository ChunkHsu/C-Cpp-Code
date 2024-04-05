#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t) {
        int ns = s.size( );
        int nt = t.size( );
        int i = 0, j = 0;
        while (i < nt)
        {
            if (s[j] == t[i])
                j++;
            i++;
        }
        if (j == ns)
            return true;
        return false;
    }
};
int main( )
{
    Solution so;
    string s = "abc", t = "ahbgdc";
    cout<<so.isSubsequence(s, t);
}