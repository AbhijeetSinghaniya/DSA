class Solution {
public:
    int dp[21][21];
    
    int solve(int i,int j,vector<int>& arr){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(arr[i] + min(solve(i+2,j,arr),solve(i+1,j-1,arr)),
                              arr[j] + min(solve(i,j-2,arr),solve(i+1,j-1,arr)));
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return true;
        
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        
        
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,n-1,nums);
        return ans >= sum - ans;
    }
};