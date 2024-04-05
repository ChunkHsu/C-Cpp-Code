#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void insertion_sort(vector<int> &vec)
{
    for(size_t i = 1; i < vec.size(); i ++)
    {
        for(size_t j = i; j > 0; j --)
        {  
            if(vec[j] < vec[j-1])
            {
                swap(vec[j], vec[j-1]);
            }
        }
    }
}

int main()
{
    vector<int> vec = {1,3,2,8,5,9};
    insertion_sort(vec);
    for(size_t i = 0; i < vec.size(); i++)
        cout<<vec[i]<<' ';
    cout<<endl;
}