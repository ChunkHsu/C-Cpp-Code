#include<bits/stdc++.h>
using namespace std;

const int N = 3e5+10;
long long s1[N], s2[N];

void solve()
{
    int n, q, l, r, x;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> x;
        s1[i] = s1[i - 1];
        s2[i] = s2[i - 1];
        if (x == 1) s1[i]++;
        s2[i] += x - 1;
    }

    while (q--) {
        cin >> l >> r;
        if (l == r || (s1[r] - s1[l - 1]) > (s2[r] - s2[l - 1]))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}