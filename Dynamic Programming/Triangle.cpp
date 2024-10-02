class Solution {
public:
    vector<vector<int>>dp;
    int help(vector<vector<int>>& triangle,int i,int j){
        if (i >= triangle.size()) return 0;
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        
        int down=triangle[i][j]+help(triangle,i+1,j);
        int right= triangle[i][j]+help(triangle,i+1,j+1);

        return dp[i][j]=min(down,right);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        //  dp.clear();
        int n = triangle.size();
        dp.resize(n, vector<int>(n, INT_MIN));
        return help(triangle,0,0);
        }
};
