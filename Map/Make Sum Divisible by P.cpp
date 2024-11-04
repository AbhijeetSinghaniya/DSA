// Exceptional use of Map and prefix sum to achieve T.C. of O(n)
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int sum = 0;
        for(int x : nums) sum += x;

        long long int rem = sum%p;
        if(rem == 0) return 0;

        int n = nums.size();
        long long int preSum = 0;
        unordered_map<long long int,int> mp;
        mp[0] = -1;

        int ans = n;
        for(int i=0;i<n;i++) {
            preSum += nums[i];
            long long int currRem = preSum%p;
            long long int target = (currRem - rem + p)%p;

            if(mp.find(target) != mp.end()) {
                ans = min(ans,i-mp[target]);
            }
            mp[currRem] = i;
        }
        return (ans == n) ? -1 : ans;
    }
};
