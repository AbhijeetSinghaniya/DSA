class Solution {
public:
    
    void solve(int s,vector<int>& v,int k){
        if(v.size() == 1) return;
        
        int n = v.size();
        // int count = k%n;
        // int x = (s+count)%n;
        s = (s+k)%n;
        
        // v.erase(v.begin()+x);
        // solve(x,v,k);
        v.erase(v.begin()+s);
        solve(s,v,k);
    }
    
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        
        for(int i=0;i<n;i++) v[i] = i;
        k--;
        solve(0,v,k);
        return v[0]+1;
    }
};