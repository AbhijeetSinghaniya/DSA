// M1 - Recursion + Memoization
class Solution {
public:
    int dp[101][101];
    int solve(int i,int j, vector<vector<int>>& og) {
        if(i == 0 && j == 0){
            if(og[i][j] == 1){
                dp[i][j] = 0;
                return 0;
            }
            return 1;
        }
        if(i < 0 || j < 0) return 0;
        if(og[i][j] == 1){
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i-1,j,og) + solve(i,j-1,og);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& og) {
        int m = og.size();
        int n = og[0].size();

        memset(dp,-1,sizeof(dp));
        return solve(m-1, n-1, og);
    }
};

// M2 - Bottom-Up
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    } 
};
