class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // map<int,int> mp;

        // int maxLastSecondRepeatingIdx = -1;

        // for(int i=0;i<nums.size();i++) {
        //     if(mp.find(nums[i]) != mp.end()) {
        //         maxLastSecondRepeatingIdx = max(maxLastSecondRepeatingIdx, mp[nums[i]]);
        //     }
        //     mp[nums[i]] = i;
        // }

        // return (maxLastSecondRepeatingIdx == -1) ? 0 : (maxLastSecondRepeatingIdx + 3)/3;
    
        map<int,int> mp;

        for(int i=nums.size()-1;i>=0;i--) {
            if(mp.find(nums[i]) != mp.end()) {
                return (i+3)/3;
            }
            mp[nums[i]] = i;
        }
        return 0;
    }
};
