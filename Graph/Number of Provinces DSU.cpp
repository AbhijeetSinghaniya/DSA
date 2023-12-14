class DisjointSet{
    vector<int> bySize,parent;
    
    public:
        DisjointSet(int size){
            parent.resize(size+1);
            bySize.resize(size+1);
            
            for(int i=0;i<=size;i++){
                parent[i] = i;
                bySize[i] = 0;
            }
        }
        int getUltimateParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = getUltimateParent(parent[node]);
        }
        int unionBySize(int u,int v){
            int up_u = getUltimateParent(u);
            int up_v = getUltimateParent(v);
            if(up_u == up_v) return 0;
            
            if(bySize[up_u] < bySize[up_v]){
                parent[up_u] = up_v;
                bySize[up_v] += bySize[up_u];
            }
            else{
                parent[up_v] = up_u;
                bySize[up_u] += bySize[up_v];
            }
            return 1;
        }
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V+1);        
        int count = 0;
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(i == j) continue;
                if(adj[i][j] == 1) count += ds.unionBySize(i+1,j+1);
            }
        }
        return V - count;
    }
};
