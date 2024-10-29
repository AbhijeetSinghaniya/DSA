// M-I : Recursion + Memoization
class Solution {
    int solve(int start, int end, vector<int>& nums,vector<int>& dp) {
        if(end < start) return 0;
        if(dp[end] != -1) return dp[end];
        return dp[end] = max(solve(start,end-1,nums,dp),
                             solve(start,end-2,nums,dp) + nums[end]);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, -1);
        int s1 = solve(0,n-2,nums,dp);
        vector<int> dp1(n, -1);
        int s2 = solve(1,n-1,nums,dp1);
        return max(s1,s2);
    }
};

// M-II : Recursion + Memoization + Space Optimization
class Solution {
    int robOriginal(vector<int>& nums) {
        int a = 0, b = 0, res = 0;  
        for(int i = 0; i < nums.size(); ++i){
            res = max(b + nums[i], a);
            b = a;
            a = res;
        }   
        return res;
    }

public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);
        
        return max(robOriginal(numsA), robOriginal(numsB));
    }
};

// M-III : Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        vector<int> dp(n-1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i=2;i<n-1;i++) {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }

        vector<int> dp1(n,0);
        dp1[1] = nums[1];
        dp1[2] = max(nums[1],nums[2]);

        for(int i=3;i<n;i++) {
            dp1[i] = max(dp1[i-1],dp1[i-2]+nums[i]);
        }
        return max(dp[n-2],dp1[n-1]);
    }
};
