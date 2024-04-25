#include<bits/stdc++.h>
using namespace std;
int dp[33];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    dp[0] = 1;
    for (int j = 1;j <= n;j++)
        for (int i = 1;i <= m;i++)
            if (j >= i)
                dp[j] += dp[j - i];
    printf("%d\n",dp[n]);
    return 0;
}