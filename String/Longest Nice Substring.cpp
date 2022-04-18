class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        if(n < 2) return "";
        
        unordered_set<int> us;
        for(int i=0;i<n;i++){
            us.insert(s[i]);
        }
        
        string prev,next;
        for(int i=0;i<n;i++){
            if(us.count(tolower(s[i])) && us.count(toupper(s[i]))) continue;
            
            prev = longestNiceSubstring(s.substr(0,i));
            next = longestNiceSubstring(s.substr(i+1,n));
            
            if(prev.length() >= next.length()) return prev;
            else return next;
        }
        return s; //to return complete string if it is Nice
    }
};
