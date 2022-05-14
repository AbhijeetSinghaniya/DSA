class Solution {
public:
    
    int solve(int i,int j,vector<int>& piles,vector<vector<int>>& dp){
        if(i > j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = max(piles[i] + min(solve(i+2,j,piles,dp),solve(i+1,j-1,piles,dp)),
                              piles[j] + min(solve(i,j-2,piles,dp),solve(i+1,j-1,piles,dp)));
        
        //return dp[i][j] = max(piles[i] + solve(i+1,j,piles,dp),piles[j] + solve(i,j-1,piles,dp));     
        //This is wrong bcoz it is returning the sum of piles only, it's just only accepted bcoz the ans is true for all cases
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int x = solve(0,n-1,piles,dp);
        
        //cout<<x;
        int sum;
        for(int i=0;i<n;i++) sum += piles[i];
        
        return x > sum/2;
      
  M - II :
      return true; // bcoz even no. of piles and sum of stones is odd, so always Alice will win
    }
};
