class Solution {
public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int,int> mp;

        for(int& x : ans) {
            mp[x]++;
        }

        int res = 0;

        for(auto i : mp) {
            int freq = i.second;
            int val = i.first + 1; //the rabbit that answered

            res += (freq/val + (freq % val != 0)) * val;
        }
        return res;
    }
};
