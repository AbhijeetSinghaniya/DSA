class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> mp;
        set<string> food;
        int n = orders.size();
        
        for(auto it : orders){
            mp[stoi(it[1])][it[2]]++;
            food.insert(it[2]);
        }
        vector<vector<string>> ans(1);
        ans[0].push_back("Table");
        
        for(auto s : food){
            ans[0].push_back(s);
        }
        
        for(auto it : mp){
            vector<string> row;
            row.push_back(to_string(it.first));
            map<string,int> m = it.second;
            
            for(auto s : food) row.push_back(to_string(m[s])); //***//
            ans.push_back(row);
        }
        return ans;
    }
};
