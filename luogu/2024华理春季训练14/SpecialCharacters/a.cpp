#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    scanf("%d", &n);
    for (int i = 0;i < n;i++) {
        scanf("%d", &k);
        if (k % 2) printf("NO\n");
        else {
            int t = k / 2;
            string ans;
            string a = "AA", b = "BB";

            int flag = 1;
            printf("YES\n");
            for (int j = 0;j < t;j++)
                if (flag) {
                    ans += a;
                    flag = 0;
                }
                else {
                    ans += b;
                    flag = 1;
                }
            cout << ans << endl;
        }
    }
}
