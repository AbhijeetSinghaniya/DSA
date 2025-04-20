// M-I - Storing subarrays in DP array - High T.C.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> subsetTillEle(n);

        int maxLen = 0;
        vector<int> ans;

        for(int i=0;i<n;i++) {

            for(int j=i-1;j>=0;j--) {
                if(nums[i] % nums[j] == 0) {
                    if(subsetTillEle[j].size() > subsetTillEle[i].size()) {
                        subsetTillEle[i] = subsetTillEle[j];
                    }
                }
            }
            subsetTillEle[i].push_back(nums[i]);
            
            if(subsetTillEle[i].size() > maxLen) {
                maxLen = subsetTillEle[i].size();
                ans = subsetTillEle[i];
            }
        }
        return ans;
    }
};

// M-II - Faster with storing the last index of subset array in current element concurrency
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxi = 0;

        sort(nums.begin(), nums.end());
        
        for(int i = 1; i < n; i ++) {
            for(int j = 0; j < i; j ++) {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > dp[maxi]) maxi = i;
        }

        vector<int> res;
        for(int i = maxi; i >= 0; i = prev[i]) {
            res.push_back(nums[i]);
        }

        return res;
    }
};
