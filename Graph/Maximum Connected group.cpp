class DisjointSet {
    vector<int> rank,parent,bySize;
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
        int getSize(int x){
            int up_x = getUltimateParent(x);
            return bySize[up_x];
        }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};          
        for(int row = 0; row < n ; row++) {
            for(int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                for(int k=0;k<4;k++){
                    int newr = row + dx[k];
                    int newc = col + dy[k];
                    int u = newr*n + newc;
                    int v = row*n + col;
                    
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1){
                        ds.unionBySize(u,v);
                    }
                }
            }
        }
        
        int maxi = INT_MIN;  
        for(int row = 0; row < n ; row++) {
            for(int col = 0; col < n ; col++) {
                if (grid[row][col] == 1) continue;
                
                set<int> components;
                for(int k=0;k<4;k++){
                    int newr = row + dx[k];
                    int newc = col + dy[k];
                    int u = newr*n + newc;                    
                    if(newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 1){
                        components.insert(ds.getUltimateParent(u));
                    }
                }
                int sizeTotal = 0;
                for(auto it : components) sizeTotal += ds.getSize(it);
                maxi = max(maxi,sizeTotal+1);
            }
        }        
        return (maxi != INT_MIN) ? maxi : n*n;
    }
};
