#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
vector<int> a, p;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        a.resize(n + 1);
        p.resize(n + 1);
        int mex = n; // a[n-1] = n - p[n-1]
        for (int i = 1; i <= n; i++)cin >> a[i];
        for (int i = n; i > 0; i--) {
            p[i] = mex - a[i];
            mex = min(mex, p[i]);
        }
        for (int i = 1; i <= n; i++)
            cout << p[i] << " ";
        cout << endl;
    }
    return 0;
}