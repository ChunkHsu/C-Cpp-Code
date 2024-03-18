#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    int32_t sum(int32_t num1, int32_t num2) {
        uint32_t u_num1 = num1, u_num2 = num2;
        while (u_num2 != 0) {
            /*进位*/
            uint32_t carry = (u_num1 & u_num2) << 1;
            /*异或*/
            u_num1 = u_num1 ^ u_num2;
            /*加数*/
            u_num2 = carry;
        }
        // 在C++中，我们可以直接返回u_num1，因为它会自动转换为int32_t
        return static_cast<int32_t>(u_num1);
    }
};

int main()
{
    class Solution so;
    int i1 = 15, j1 = -2;
    cout << so.sum(i1, j1) << endl;
    
}