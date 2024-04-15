#include<bits/stdc++.h>
using namespace std;
int dp[4][7];
// int dp[5001][5001];
int w[5001];
int v[5001];

// 二维背包
int twoDim(int n, int m)
{
    for (int i = 0;i < n;i++)
        scanf("%d", &w[i]);
    for (int i = 0;i < n;i++)
        scanf("%d", &v[i]);

    // 初始化背包
    for (int j = w[0];j <= m;j++)
        dp[0][j] = v[0];

    // 正序遍历背包
    for (int i = 1;i < n;i++)
        for (int j = 0;j <= m;j++)
            if (j < w[i]) // 如果当前背包的容量装不下第i个物品
                dp[i][j] = dp[i - 1][j];
            else // 当前背包的容量可以装下第i个物品
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);

    // 倒序遍历背包
    // for (int i = 1;i < n;i++)
    //     for (int j = m;j > 0;j--)
    //         if (j < w[i])
    //             dp[i][j] = dp[i - 1][j];
    //         else
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);

    return dp[n - 1][m];
}

// 一维背包
int oneDim(int m, int n)
{
    for (int i = 0;i < m;i++)
        scanf("%d", &w[i]);
    for (int i = 0;i < m;i++)
        scanf("%d", &v[i]);

    // 初始化背包
    vector<int> dp(n + 1, 0);

    for (int i = 0;i < m;i++) // 遍历物品
        for (int j = n;j >= w[i];j--) // 倒叙遍历背包,且当前背包的容量可以装下第i个物品
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    return dp[n];
}
int main( )
{
    int m, n, ans;
    scanf("%d %d", &m, &n);

    ans = twoDim(m, n);
    // ans = oneDim(m, n);

    printf("%d\n", ans);
    return 0;
}
/*
3 4
1 3 4
15 20 30

4 6
3 4 5 3
3 1 6 7

*/