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

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        int edges = edge.size();
        
        if(edges < n-1) return -1;
        
        int totalComponents = n;
        DisjointSet ds(n+1);
        
        for(int i=0;i<edges;i++){
            if(ds.getUltimateParent(edge[i][0]) != ds.getUltimateParent(edge[i][1])){
                ds.unionBySize(edge[i][0],edge[i][1]);
                totalComponents--;
            }
        }
        return totalComponents-1;
    }
};
