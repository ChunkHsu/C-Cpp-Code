#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        queue<int> q;
        int flag = 0,tmp,ans=1;
        q.push(1);
        for (int i = 2;i <= n;i++)
        {
            if (flag) // odd
            {
                tmp = q.front( );
                q.pop( );
                tmp += q.front( );
                q.push(tmp);
                ans = tmp;
                flag--;
            }
            else // even
            {
                tmp = q.front( );
                q.push(tmp);
                flag++;
            }
            cout << ans << " " << i <<endl;
            for (int t = 0;t < q.size( );t++)
            {
                cout << q.front( ) << " ";
                q.push(q.front( ));
                q.pop( );
            }
            cout << endl;
        }
        return ans;
    }
};
int main( )
{
    Solution so;
    cout << so.getMaximumGenerated(15);
}