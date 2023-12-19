class DisjointSet{
    vector<int> parent,bySize;
    public:
        DisjointSet(int size){
            parent.resize(size+1);
            bySize.resize(size+1);
            for(int i=0;i<=size;i++){
                parent[i] = i;
                bySize[i] = 1;
            }
        }
        int getUltimateParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = getUltimateParent(parent[node]);
        }
        
        void unionBySize(int u,int v){
            int up_u = getUltimateParent(u);
            int up_v = getUltimateParent(v);
            if(up_u == up_v) return;
            
            if(bySize[up_u] < bySize[up_v]){
                parent[up_u] = up_v;
                bySize[up_v] += bySize[up_u];
            }
            else{
                parent[up_v] = up_u;
                bySize[up_u] += bySize[up_v];
            }
        }
};

class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet ds(n+1);
        unordered_map<string,int> mapMailNode;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){ //starting from mails
                if(mapMailNode.find(accounts[i][j]) == mapMailNode.end()){
                    mapMailNode[accounts[i][j]] = i;
                }
                ds.unionBySize(i,mapMailNode[accounts[i][j]]);
            }
        }
        
        vector<string> mergeMails[n];
        for(auto it : mapMailNode){
            string mail = it.first;
            int node = ds.getUltimateParent(it.second);
            
            mergeMails[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(mergeMails[i].size() == 0) continue;
            
            sort(mergeMails[i].begin(),mergeMails[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMails[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
