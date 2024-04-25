#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX); // 容量为 j 时，最少的个数为 dp[j] 个
        int t = sqrt(n);
        vector<int> w(t + 1);

        for (int i = 0;i <= t;i++) // 每个容量为 i*i
            w[i] = i * i;

        dp[0] = 0;
        for (int i = 1;i < t + 1;i++)
            for (int j = w[i];j <= n;j++)
                if(dp[j - w[i]] != INT_MAX) // 当前一个状态可达时
                    dp[j] = min(dp[j], dp[j - w[i]] + 1);
        
        if (dp[n] == INT_MAX)return 0;
        return dp[n];
    }
};

int main()
{
    Solution so;
    int n = 12;
    cout << so.numSquares(n) << endl;
}