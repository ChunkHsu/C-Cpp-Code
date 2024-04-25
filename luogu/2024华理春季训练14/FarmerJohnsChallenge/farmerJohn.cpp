#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, k;
    vector<string> ans;
    scanf("%d", &m);
    for (int i = 0;i < m;i++) {
        scanf("%d %d", &n, &k);
        if (n == k) {
            string tmp = "";
            for (int i = 0;i < n;i++)
                tmp += "1 ";
            ans.push_back(tmp);
        }
        else if (n > k && k == 1) {
            string tmp = "";
            for (int i = 0;i < n;i++)
                tmp += to_string(i + 1) + " ";
            ans.push_back(tmp);
        }
        else
            ans.push_back("-1");
    }
    for (string s : ans)
        cout << s << endl;
    return 0;
}