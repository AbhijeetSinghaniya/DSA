class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        vector<int> tmp(100001, 0);
        for (auto& n : nums) {
            tmp[n+50000]++;
        }
        vector<int> ans;
        for (int i = 0; i < tmp.size(); i++) {
            while (tmp[i]-- != 0) {
                ans.push_back(i-50000);
            }
        }
        return ans;
        
        // sort(nums.begin(),nums.end());
        // return nums;
    }
};
