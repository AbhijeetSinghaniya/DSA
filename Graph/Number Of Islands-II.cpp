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
        int unionBySize(int u,int v) {
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>>& A) {
            int nodes = n*m;
            DisjointSet ds(nodes);
            
            vector<vector<int>> graph(n,vector<int> (m,0));
            vector<int> ans;
            int dx[] = {0,0,1,-1};
            int dy[] = {1,-1,0,0};
            
            for(int i=0;i<A.size();i++){
                if(graph[A[i][0]][A[i][1]] == 1) {
                    ans.push_back(ans[i-1]);
                    continue;
                }
                graph[A[i][0]][A[i][1]] = 1;
                int cnt = 1;
                
                for(int j=0;j<4;j++){
                    int x = A[i][0]+dx[j];
                    int y = A[i][1]+dy[j];
                    int u = x*m + y;
                    int v = A[i][0]*m + A[i][1];
                    
                    if(x>=0 && y>=0 && x<n && y<m && graph[x][y] == 1){
                        cnt -= ds.unionBySize(u,v);
                    }
                }
                int temp = (i != 0) ? (ans[i-1] + cnt) : 1;
                ans.push_back(temp);
            }
            return ans;
    }
};
