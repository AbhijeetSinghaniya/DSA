class Solution {
public:
    int lengthOfLongestSubstring(string s){
        map<char,int> mp;
        int ans = 0;
        int l = 0;
        
        for(int r=0;r<s.length();r++){
            if(mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]] + 1,l); //most crucial condition
            }
            mp[s[r]] = r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};