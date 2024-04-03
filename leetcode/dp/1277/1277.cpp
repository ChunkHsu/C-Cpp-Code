#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n;
        if(m) n = matrix[0].size();
        else return 0;
        int ans=0;
        int width = max(m,n);
        for(int t=0;t<width;t++)
        {
            for(int i=0;i<m-t;i++)
            {
                for(int j=0;j<n-t;j++)
                {
                    if(matrix[i][j])
                    {
                        if(t){
                            if(matrix[i+1][j]==t && matrix[i][j+1]==t && matrix[i+1][j+1]==t)
                            {
                                ans++;
                                matrix[i][j]++;
                            }
                        }
                        else
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    Solution so;
    vector<vector<int>> matrix={{1,0,1},{1,1,0},{1,1,0}};
    cout<<so.countSquares(matrix)<<endl;

}