#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e4 + 1;
int w[N];
int v[N];
int k[N];
ll dp[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int c, n;
    cin >> c >> n;
    for (int i = 0; i < n; i++)
        cin >> w[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> k[i];

    for (int i = 0;i < n;i++) { // 每类物品
        for (int kk = 0;kk < k[i];kk++) { // 每类物品的数量
            for (int j = c;j >= w[i];j--) { // 背包容量
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    cout << dp[c] << endl;
    return 0;
}