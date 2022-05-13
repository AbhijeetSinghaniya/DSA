class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        map<char,int> freq;
        
        for(auto c : s) freq[c]++;
        
        priority_queue<pair<int,char>> maxh;
        
        for(auto it : freq){
            maxh.push({it.second,it.first});
        }
        
        string ans = "";
        pair<int,char> prev = {-1,'#'};
        while(!maxh.empty()){
            auto curr = maxh.top();
            maxh.pop();
            
            ans += curr.second;
            
            if(prev.first > 0) maxh.push(prev);
            
            curr.first--;
            prev = curr;
        }
        if(ans.length() == n) return ans;
        return "";
    }
};
