#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size( );
        int i = 0, j = n-1;
        while (i<=j)
        {
            while (i<n && !isalpha(s[i]) && !isdigit(s[i]))i++;
            while (j>=0 && !isalpha(s[j]) && !isdigit(s[j]))j--;
            if(i>=n || j<0)
                break;
            if (toupper(s[i]) != toupper(s[j]))
                return false;
            i++;j--;
        }
        return true;
    }
};
int main( )
{
    Solution so;
    cout<<so.isPalindrome("0P");
}