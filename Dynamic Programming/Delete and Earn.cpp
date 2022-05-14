class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> values(n, 0);
        for (int num : nums)
            values[num] += num;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int takei = skip + values[i];
            int skipi = max(skip, take);
            take = takei;
            skip = skipi;
        }
        return max(take, skip);
    }
};

//M - II : same logic, just different way of writing code
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> freq(mx+1,0),dp(mx+1,0);
        for(int i=0; i<n; i++) freq[nums[i]]++;
        dp[0]=0; dp[1]=freq[1]; dp[2]=max(dp[1],freq[2]*2);
        for(int i=3; i<=mx; i++){
            dp[i]=max(dp[i-1],dp[i-2]+freq[i]*i);
        }
        return dp[mx];
    }
};
