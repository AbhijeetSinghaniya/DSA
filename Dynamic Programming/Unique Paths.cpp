// M1 - Recursion + Memoization
class Solution {
public:
    int dp[101][101];
    int solve(int i, int j) {
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = solve(i-1,j) + solve(i, j-1);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        long long int ans = solve(m-1,n-1);
        return ans;
    }
};

// M2 - Bottom-Up
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Storing in dp the number of ways you can reach on that particular cell
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// M3 - Permutation and Combination
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        long int res = 1;
        
        for(int i=1;i<=r;i++){
            res = res*(N-r+i)/i;
        }   
        return res;
    }
};
