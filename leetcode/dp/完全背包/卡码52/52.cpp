#include<bits/stdc++.h>
using namespace std;
int dp[10001];
int w[10001];
int v[10001];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0;i < n;i++)
        scanf("%d %d", &w[i], &v[i]);

    // for (int i = 0;i < n;i++)
    //     for (int j = w[i];j <= m;j++)
    //         dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    for (int j = 0;j <= m;j++)
        for (int i = 0;i < n;i++)
            if (j >= w[i])
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    

    printf("%d\n", dp[m]);
}