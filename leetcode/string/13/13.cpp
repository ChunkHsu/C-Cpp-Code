#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
    int getV(char ch)
    {
        switch(ch) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
    }
public:
    int romanToInt(string s) {
        unordered_map<char, int>rom{{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M',1000}};
        int n = s.size( );
        int ans = rom[s[n - 1]];
        for (int i = n - 2; i >= 0;i--)
        {
            if (rom[s[i]] < rom[s[i + 1]])
                ans -= rom[s[i]];
            else
                ans += rom[s[i]];
        }
        return ans;
    }
};
int main( )
{
    Solution so;
    string s = "LVIII";
    cout<<so.romanToInt(s);
}
