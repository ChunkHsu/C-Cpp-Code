// #include<bits/stdc++.h>
// #include<algorithm> // fill_n
// using namespace std;
// class Solution
// {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size( );
//         int dp[n][n];
//         fill_n(&dp[0][0], n * n, 2);
//         // vector<vector<int>> dp(n, vector<int>(n, 1));
//         int ans = 0;
//         int maxl = 1;
//         for (int i=n-1;i>=0;i--)
//         {
//             for (int j = i+1;j < n;j++)
//             {
//                 dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
//                 if (dp[i][j] && j - i + 1 > maxl)
//                 {
//                     maxl = j - i + 1;
//                     ans = i;
//                 } 
//             }
//         }
//         return s.substr(ans, maxl);
//     }
// };


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size( );
        int maxl = 1;
        int ans = 0;
        int dp[n][n];
        // 初始化
        for (int i = 0;i < n;i++)
            for (int j = 0;j <= i;j++)
                dp[i][j] = 1;
        // dp[i][j]=1, s[i]--s[j] 是回文串
        for (int i = n - 1;i >= 0;i--)
            for (int j = i + 1;j < n;j++)
            {
                dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (j - i + 1 > maxl && dp[i][j])
                {
                    maxl = j - i + 1;
                    ans = i;
                }
            }
        
        return s.substr(ans, maxl);
    }
};
int main()
{
    // ababc aba
    Solution so;
    string s = "abb";
    cout << so.longestPalindrome(s) << endl;
}