#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

class Solution
{
    string getV(int res ,int i)
    {
        string ans="";
        string five[3] = { "V", "L", "D" };
        string ten[4] = {"I", "X", "C", "M"};
        if (res < 4)
        {
            for (int t = 0;t < res;t++)
                ans += ten[i];
        }
        else if (res == 4)
            ans += five[i] + ten[i];
        else if (res == 5)
        {
            ans += five[i];
        }
        else if (res>5 && res<9)
        {
            for (int t = 0;t < res % 5;t++)
                ans += ten[i];
            ans += five[i];
        }
        else if (res == 9)
            ans += ten[i + 1] + ten[i];
        return ans;
    }
public:
    string intToRoman(int num) {
        string ans="";
        int i = 0;
        while (num / 10)
        {
            int res = num % 10;
            ans += getV(res, i);
            i++;
            num /= 10;
        }
        ans += getV(num , i);
        reverse(ans.begin( ), ans.end( ));
        return ans;
    }

    string intToRoman2(int num )
    {
        string ans = "";
        int values [ ] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
        string charters [ ] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        for (int i = 0; i < 13;i++)
        {
            while (num >= values[i])
            {
                num -= values[i];
                ans += charters[i];
            }

        }
        return ans;
    }
};
int main( )
{
    Solution so;;
    cout<<so.intToRoman2(14);
    return 0;
}
