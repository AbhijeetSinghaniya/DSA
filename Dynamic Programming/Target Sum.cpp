class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0, count0 = 0, multi = 1;
        for(auto x : nums){
            totalSum += x;
            if(x == 0) multi *= 2;
        }
        if(target < 0) target = abs(target); //Corner case

        if((totalSum+target)%2 == 1 || totalSum < target) return 0;
        int sum = (totalSum+target)/2;

        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++) dp[i][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1] <= j && nums[i-1] != 0) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum]*multi;
    }
};
