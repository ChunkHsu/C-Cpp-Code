#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[j][k] 在 0 背包容量为 j， 1 背包容量为 k 时， 能装的最长子串为 dp[j][k] 个

        for (string str : strs) {
            int one = 0, zero = 0;
            for (char c : str) // 计算每个str中 0 与 1 的个数
                if (c == '0') zero++;
                else one++;
            
            for (int j = m;j >= zero;j--)
                for (int k = n;k >= one;k--)
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1); // 当前这个 str 装或者不装 
        }

        return dp[m][n];
    }
};
int main()
{
    Solution so;
    vector<string> strs = {"10", "0", "1"};
    cout << so.findMaxForm(strs,1,1) << endl;
}