bool comp(int a, int b) {
    string a1 = to_string(a),b1 = to_string(b);
    return a1+b1 > b1+a1;
}
class Solution {
public:

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        int n = nums.size();
        string ans = "";
        for(int i=0;i<n;i++){
            // cout<<nums[i]<<"  ";
            ans += to_string(nums[i]);
        } 
        while(ans[0] == '0' && ans.length() > 1) ans.erase(0,1);
        return ans;
    }
};
