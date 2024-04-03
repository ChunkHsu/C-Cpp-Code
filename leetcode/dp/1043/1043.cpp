#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> f(k+1,0); // 存放前k个的max
        int max_arr=arr[0]; // 记录当前的max
        f[k-1]=arr[0];
        int l=0; // 循环数组
        for(int i=1;i<n;i++)
        {
            max_arr = arr[i];
            int tmp;
            for(int j=1;j<=k;j++)
            {
                if(i-j+1 < 0)
                    break;
                max_arr = max(arr[i-j+1],max_arr);
                tmp = f[(l+k-j)%(k+1)] + j*max_arr; // 状态转移方程
                int cur = (l+k)%(k+1);
                if(tmp > f[cur])
                    f[cur]=tmp;
            }
            l++;
            // 移动
        }
        return f[(l+k-1)%(k+1)];
    }
};
int main()
{
    Solution so;
    vector<int> a={1,4,1,5,7,3,6,1,9,9,3};
    cout<<so.maxSumAfterPartitioning(a, 4)<<endl;
}