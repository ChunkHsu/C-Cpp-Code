#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int ans=0;
        // 将引用次数排序一下，方便统计数目
        sort(citations.begin(), citations.end());
        
        for(int i=0; i<n; i++)
        {
            // 如果引用次数大于总引用论文的数量时
            if(citations[i]>n-i)
                // 将h指数降为总引用论文的数量，并取最大值
                ans=max(n-i, ans);
            // 如果引用次数小于等于总引用论文的数量时
            if(citations[i]<=n-i)
                // 此时h指数为引用的次数，且取最大值
                ans=max(citations[i], ans);
        }
        return ans;
    }
};
int main()
{
    Solution so;
    vector<int> nums{4};
    cout<<so.hIndex(nums)<<endl;
}


