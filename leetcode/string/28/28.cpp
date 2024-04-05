#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
https://www.zhihu.com/question/21923021/answer/281346746
*/
class Solution
{
    // KMP 算法，获得PMT的next数组
    vector<int> getPMTNext(string str)
    {
        int n = str.size( );
        vector<int> next(n+1, 0); // PMT 的值后移一位
        next[0] = -1;
        int i = 0, j = -1;
        while (i < n)
        {
            if (j == -1 || str[i] == str[j])
            {
                next[++i] = ++j; // 将最大的公共前后缀放到下个next中
            }
            else
                j = next[j];
        }
        return next;
    }
public:
    int strStr(string haystack, string needle)
    {
        // return haystack.find(needle);
        vector<int> next = getPMTNext(needle);
        int ne_len = needle.size( );
        int ha_len = haystack.size( );
        int i = 0;
        int j = 0;
        while (i < ha_len && j < ne_len)
        {
            if ( j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            else
                j = next[j];
        }
        if (j == ne_len)
            return i - j;
        return -1;
    }

};

int main( )
{
    string a = "sadbutsad", b = "sad";
    Solution so;
    cout << so.strStr(a, b) << endl;
}