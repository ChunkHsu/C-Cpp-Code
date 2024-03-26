#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size( );
        if (numRows == 1)
            return s;
        string newS;
        int len = 2 * numRows - 2;
        int i = 0;
        while (i * len < n)
            newS.push_back(s[len * i++]);

        i = 1;
        while (i < numRows)
        {
            int nlen = 0;
            while (nlen<n)
            {
                if (i + nlen < n)
                    newS.push_back(s[i + nlen]);
                int mi = len - i + nlen;
                if (mi < n && mi != i + nlen)
                    newS.push_back(s[mi]);
                nlen += len;
            }
            i++;
        }
        return newS;
    }

    string convert2(string s, int numRows)
    {
        if (numRows < 2)return s;
        vector<string> slot(numRows);
        int i = 0;
        int dir = -1;
        for (char c : s)
        {
            slot[i].push_back(c);
            if (i == 0 || i == numRows - 1)
                dir = -dir;
            i += dir;
        }
        for (int i = 1;i < numRows;i++)
            slot[0] += slot[i];
        return slot[0];
    }
};
int main( )
{
    Solution so;
    string s = "adhebfigc";
    cout<<so.convert2(s, 3);
}
