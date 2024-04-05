#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // 双指针
    int maxArea(vector<int> &height)
    {
        int n = height.size( );
        int i = 0, j = n - 1;
        int v = 0;
        while (i < j)
        {
            if (height[i] <= height[j])
            {
                v = max(height[i] * (j - i), v);
                i++;
            }
            else
            {
                v = max(height[j] * (j - i), v);
                j--;
            }
        }
        return v;
    }
};
int main( )
{
    Solution so;
    vector<int> hh = { 1,8,6,2,5,4,8,3,7 };
    cout << so.maxArea(hh);
}