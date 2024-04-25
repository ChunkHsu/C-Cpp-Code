#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(0);
        for (int i = 1;i < n;i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
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
    vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
    for (int i : so.dailyTemperatures(temperatures)) {
        cout << i << " ";
    }
    return 0;
}