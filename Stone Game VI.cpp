bool comp(vector<int>& a,vector<int>& b){
    if(a[0] > b[0]) return true;
    else if(a[0] < b[0]) return false;
    else if(a[0] == b[0]){
        if(a[1] > b[1]) return true; //if(a[1] >= b[1]) -> both ">" && "=" 
                                    // are not valid together here
        else return false;
    }
    return false; //dummy return
}

class Solution {
public:
    
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        vector<vector<int>> v;
        int n = a.size();
        
        for(int i=0;i<n;i++){
            v.push_back({a[i]+b[i],a[i],b[i]});
        }
        sort(v.begin(),v.end(),comp);
        
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(i%2 == 0) x += v[i][1];
            else y += v[i][2];
        }
        if(x == y) return 0;
        else if(x > y) return 1;
        else return -1;
    }
};