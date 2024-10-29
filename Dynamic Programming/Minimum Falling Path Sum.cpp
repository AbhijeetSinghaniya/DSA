class Solution {
    int solve(int i, int j, int r,int c, vector<vector<int>>& matrix, 
              vector<vector<int>>& dp) {

        if(i >= r) return 0;

        if(j < 0 || j >= c) return 10002;

        if(dp[i][j] != -100000) return dp[i][j];
        
        int left = solve(i+1,j-1,r,c,matrix,dp);
        int down = solve(i+1,j,r,c,matrix,dp);
        int right = solve(i+1,j+1,r,c,matrix,dp);

        return dp[i][j] = matrix[i][j] + min({left,down,right});
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> dp(r,vector<int>(c, -100000));
        int mini = INT_MAX;
        for(int j=0;j<c;j++) {
            mini = min(mini, solve(0,j,r,c,matrix,dp));
        }
        return mini;
    }
};
