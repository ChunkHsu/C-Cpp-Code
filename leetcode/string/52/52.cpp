#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int flag = 0;
        for (string::reverse_iterator it = s.rbegin( ); it != s.rend( );it++)
        {
            if (*it == ' ')
                if (flag)
                    break;
                else
                    continue;
            else
            {
                flag = 1;
                ans++;
            }
        }
            
        return ans;
    }
};
int main()
{
    Solution so;
    string s="   fly me   to   the moon  ";
    cout << so.lengthOfLastWord(s) << endl;
}
