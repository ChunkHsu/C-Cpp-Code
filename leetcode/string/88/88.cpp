# include <iostream>
# include <vector>

using namespace std;

class Solution {
public://[2, 0] [1]
    // 移动元素 O(nlgn)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i=0, j=0, oi=0;
        int nums1_i = 0;
        while(i<m && j<n)
        {   
            nums1_i = i + oi;
            if(nums1[nums1_i]<= nums2[j])
            {
                i++;
            }
            else
            {
                for(int i2= m+n-1; i2 > nums1_i; i2--)
                    nums1[i2] = nums1[i2-1];
                nums1[nums1_i] = nums2[j++];
                oi++;
            }
        }
        nums1_i = i + oi;
        while(j<n)
        {
            nums1[nums1_i++] = nums2[j++];
        }
    }
    // 从后往前填充 O(m+n)
    void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i=m-1, j=n-1, ri = m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[ri] = nums1[i--];
            }
            else
            {
                nums1[ri] = nums2[j--];
            }
            ri--;
        }
        while(j>=0)
        {
            nums1[ri--] = nums2[j--];
        }
    }
};

int main()
{
    Solution so;
    vector<int> nums1={2, 0},nums2 = {1};

    so.merge2(nums1, 1, nums2, 1);
    for(auto &p :nums1)
        cout<< p << " ";
    cout<< endl;
}