class DisjointSet {
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
        void unionBySize(int u,int v) {
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

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = -1,maxCol = -1;        
        for(auto v : stones){
            maxRow = max(maxRow,v[0]);
            maxCol = max(maxCol,v[1]);
        }
        
        DisjointSet ds(maxRow+maxCol+2);   //Since row and column both are zero indexing
        unordered_map<int,int> stoneNodes; //We need only those nodes who have stones with it
        for(auto it : stones){
            int u = it[0];
            int v = it[1] + maxRow + 1;
            ds.unionBySize(u,v);
            stoneNodes[u] = 1;
            stoneNodes[v] = 1;
            
        }   
      
        int totalComponents = 0;
        for(auto it : stoneNodes){
            if(ds.getUltimateParent(it.first) == it.first) totalComponents++;
        }
        return n - totalComponents;
    }
};
