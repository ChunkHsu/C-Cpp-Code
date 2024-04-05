#include<iostream>

using namespace std;

//5 1 p
//3 1 q
//1 3 r
void sum()
{
    for(int p = 0;p<100/5+1;p++ )
    {
        for(int q = 0;q <100/3+1;q++)
        {
            int res = 100 - (5*p + 3*q);
            int num = res*3 + p + q;
            if(num == 100)
                cout<<p<<" "<<q<<" "<<res * 3<<endl;
        }
    }
}
int main()
{
    sum();
    return 0;
}