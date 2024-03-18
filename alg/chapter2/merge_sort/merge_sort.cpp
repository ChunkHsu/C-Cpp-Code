#include <vector>
#include <iostream>

using namespace std;
/*归并排序*/

class Solution
{
public:
    vector<int> sortArray(vector<int>& nums) {
        merge_sort(nums, 0, nums.size()-1);
        return nums;
    }
private:
    /*合并*/
    void merge(vector<int> &nums, int p, int q, int r)
    {
        vector<int> left(nums.begin()+p,nums.begin()+q+1);
        vector<int> right(nums.begin()+q+1,nums.begin()+r+1);
        
        unsigned int ll =0, rr= 0, i = p;
        while(ll<left.size() && rr<right.size())
        {
            if(left[ll] <= right[rr])
                nums[i++] = left[ll++];
            else
                nums[i++] = right[rr++];
        }

        while(ll<left.size())
            nums[i++] = left[ll++];
        
        while(rr<right.size())
            nums[i++] = right[rr++];
    }
    /*分支*/
    void merge_sort(vector<int> &nums, int p, int r)
    {
        if(p<r)
        {
            int q = p + (r-p)/2;
            merge_sort(nums, p, q);
            merge_sort(nums, q+1, r);
            merge(nums, p, q, r);
        }
    }
};

int main( )
{
    Solution solution;
    vector<int> data = {3,41,52,26,38,57,9,49};
    vector<int> sorted_data = solution.sortArray(data);

    for (int num : sorted_data) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
