#include<iostream>
#include<vector>

using namespace std;

class Solution
{
    vector<int> mem;
public:
    Solution( ) : mem(64, -1) { }
    int fib(int n)
    {
        if (n <= 1)
        {
            mem[n] = n;
            return n;
        }
        if (mem[n] != -1)
            return mem[n];
        else
        {
            mem[n] = fib(n - 1) + fib(n - 2);
            return mem[n];
        }
    }
};

int main( )
{
    Solution s;
    int n = 10;
    cout << s.fib(n) << endl;
}