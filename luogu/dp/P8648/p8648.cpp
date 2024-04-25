#include<bits/stdc++.h>
using namespace std;
const int MAX_DP = 100005;
int dp[MAX_DP];
int w[101];

int gcd(int m, int n)
{
    if (n)
        return gcd(n, m % n);
    else
        return m;
}
bool isOne(int* w, int n)
{
    int g = w[0];
    for (int i = 1;i < n;i++) {
        g = gcd(g, w[i]);
        if (g == 1)
            return true;
    }
    return g == 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0;i < n;i++)
        scanf("%d", &w[i]);
    
    
    if (!isOne(w, n)) {
        printf("INF\n");
        return 0;
    }

    dp[0] = 1;
    for (int i = 0;i < n;i++)
        for (int j = w[i];j <= MAX_DP;j++)
            dp[j] = max(dp[j], dp[j - w[i]]);
    int ans = 0;
    for (int i = 0;i <= MAX_DP;i++)
        if (!dp[i])
            ans++;

    printf("%d\n", ans);
    return 0;
}