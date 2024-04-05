#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<utility>

using namespace std;

class Solution
{
public:
    string reverseWords(string s) {
        stack<string> ans;
        int n = s.size( );
        int i = 0;
        while (i<n)
        {
            string tmp="";
            while (s[i] != ' ' && i < n)
            {
                tmp += string(1, s[i]);
                i++;
            }
            if(tmp!="")
                ans.push(tmp);
            i++;
        }
        string ans_string="";
        while (!ans.empty( ))
        {
            ans_string += ans.top( );
            ans.pop( );
            if (ans.empty( ))
                return ans_string;
            ans_string += " ";
        }
        return "";
    }

    string reverseWord2(string s )
    {
        reverse(s.begin( ), s.end( ));
        
        int n = s.size( );
        int i = 0, j = 0, t = 0;

        while (s[i] == ' ' && i < n)i++;
        while (i < n)
        {
            while (s[i] != ' ' && i < n)
                s[j++] = s[i++];
            
            while (s[i] == ' ' && i < n)i++;
            reverse(s.begin( ) + t, s.begin( ) + j);

            s[j++] = ' ';
            t = j;
        }
        
        return s.substr(0,t-1);
    }
};

int main( )
{
    Solution so;
    string s = " hello world  ";
    cout << "*" << so.reverseWord2(s) << "*" << endl;
}