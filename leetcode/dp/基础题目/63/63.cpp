#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int n = obstacleGrid.size( );
        int m = obstacleGrid[0].size( );
        int dp[n+1][m+1]; // dp[i][j] = k 到达i,j有k种方法,额外添加一层,不用额外判断边界条件
        memset(dp, 0, sizeof dp);
        dp[0][1] = 1;
        for (int i = 1;i <= n;i++){
            for (int j = 1;j <= m;j++){
                if (obstacleGrid[i-1][j-1]){//当点是障碍物
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};
int main( )
{
    // obstacleGrid = [[1,0],[0,0]]
    Solution so;
    vector<vector<int>> obstacleGrid = { {0,0,0},{0,1,0},{0,0,0} };
    // vector<vector<int>> obstacleGrid = { {0,0},{0,0},{0,1} };
    cout << so.uniquePathsWithObstacles(obstacleGrid) << endl;
}