#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>::iterator it = lower_bound(numbers.begin( ), numbers.end( ), target / 2);
        int index = distance(numbers.begin( ), it);
        if (index - 1 >= 0)
            index--;
        int ans = numbers[index] + 
        while ()
        {
            
        }
    }
};
int main( )
{
    std::vector<int> v = {2,7,11,15};

    // 查找第一个不小于4的元素 
    // lower_bound >= 4 的元素的迭代器
    // upper_bound > 4 的元素的迭代器
    cout << -1 / 2;
    auto it = std::lower_bound(v.begin( ), v.end( ), 2);
    int index = distance(v.begin( ), it);
    cout << index << " " << v[index]<<endl;
    cout << *it << endl;

    return 0;
}