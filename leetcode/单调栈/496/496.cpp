#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, int> umap; // 因为键值唯一，可以用map
        for (int i = 0;i < m;i++)
            umap[nums1[i]] = i;

        vector<int> ans(m, -1);
        stack<int> st;
        st.push(0);
        for (int i = 1;i < n;i++) { // 对nums2进行单调栈
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                int tv = nums2[st.top()];
                if (umap.count(tv) > 0) // nums1 的值存在
                    ans[umap[tv]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
int main()
{
    Solution so;
    return 0;
}