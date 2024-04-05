// 输入：nums = [1,1,1,2,2,3]
// 输出：5, nums = [1,1,2,2,3]
// 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
# include<iostream>
# include<vector>

using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=1, n=nums.size();
        if(n<=2)
            return n;
        
        bool flag=0;
        for(int j = 1; j < n; j++)
        {
            if(nums[j] == nums[i-1])
            {
                if(!flag){
                    flag =1;
                    if(i==0)
                        i=1;
                    nums[i++] = nums[j];
                }
            }
            else
            {   
                flag = 0;
                nums[i++] = nums[j];
            }
        }
        return i;
    }
    /*保留k个重复元素*/
    int removeDuplicates2(vector<int>& nums)
    {
        int k=2;
        int ans=0;
        int n=nums.size();
        for(int i =0;i<n;i++)
        {
            if(i<k || nums[ans-k] != nums[i])
                nums[ans++] = nums[i];
        }
        return ans;
    }
};

int main()
{
    Solution so;
    vector<int> nums={0,0,1,1,1,1,2,3,3};
    cout<<so.removeDuplicates2(nums)<<endl;
}
