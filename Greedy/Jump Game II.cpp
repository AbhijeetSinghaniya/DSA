// This code will fail as we are sending count as variable to same index with different count values
// Ex : [2,3,1,3,4,6] --> Here, value 1 will receive two count values as 1 and 2 from index 0 and 1 respectively
int solve(int start,int end, vector<int>& nums,int cnt,int n,vector<int>& dp) {
    if(start >= end) {
        return cnt;
    }
    if(dp[start] != -1) return dp[start];
    
    int ans = INT_MAX;
    for(int i=start+1;i<n && i<=nums[start]+start;i++) {
        int x = solve(i,end,nums,cnt+1,n,dp);
        ans = min(ans,x);
    }
    return dp[start] = ans;
}

//M-I : Correct Recursion + Memoization
int solve2(int start,int end, vector<int>& nums,int n,vector<int>& dp) {
    if(start >= end) {
        return 0;
    }
    if(dp[start] != -1) return dp[start];
    
    int ans = INT_MAX;
    for(int i=start+1;i<n && i<=nums[start]+start;i++) {
        int x = solve2(i,end,nums,n,dp);
        if(x != INT_MAX) ans = min(ans,x+1);
    }
    return dp[start] = ans;
}

class Solution {
public:
  int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        // vector<int> dp(n,-1);
        // return solve2(0,n-1,nums,n,dp);

  //M-II : O(n) linear Greedy solution
        int i = 0;
        int currMax = 0;
        int cnt = 0;
        while(i < n) {
            if(currMax >= n-1) break;

            int record = 0;
            while(i < n && i <= currMax) {
                record = max(record,nums[i]+i);
                ++i;
            }
            if(record > currMax) {
                currMax = record;
                cnt++;
            }
        }
        return cnt;
    }
};
