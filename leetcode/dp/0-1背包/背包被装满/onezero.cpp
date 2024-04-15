#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> w(m), v(n);
    for (int i = 0;i < m;i++)
        cin >> w[i];
    for (int i = 0;i < m;i++)
        cin >> v[i];
    // vector<int> dp(n + 1, 0);
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 0;i < m;i++){
        for (int j = n;j >= w[i];j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            cout << "-" << endl;
        }
    }
    cout << dp[n] << endl;
}
/*
4 5
2 3 4 5
2 2 10 9

4 5
2 2 4 4
2 2 10 9
*/