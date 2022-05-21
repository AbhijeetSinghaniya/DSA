class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        dp[n] = 0;
        dp[n-1] = cost[n-1];
        
        for(int i=n-2;i>=0;i--){
            dp[i] = min(cost[i]+dp[i+2],cost[i]+dp[i+1]); //**start from end**
        }
        return min(dp[0],dp[1]);
    }
};
