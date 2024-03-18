#include<iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int> & nums)
{
    for (unsigned int i = 0; i < nums.size() - 1; i++)
    {
        for (unsigned j = i; j < nums.size( ); j++)
        {
            if (nums[i] > nums[j])
                swap(nums[i], nums[j]);
        }
    }
}

int main( )
{
    vector<int> nums = {1,2,5,4};
    bubble_sort(nums);
    for (auto &p : nums)
        cout << p << " ";
    cout << endl;
}