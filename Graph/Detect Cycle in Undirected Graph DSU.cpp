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

        int unionBySize(int u,int v) {
            int up_u = getUltimateParent(u);
            int up_v = getUltimateParent(v);
            if(up_u == up_v) return 1;
            
            if(bySize[up_u] < bySize[up_v]){
                parent[up_u] = up_v;
                bySize[up_v] += bySize[up_u];
            }
            else{
                parent[up_v] = up_u;
                bySize[up_u] += bySize[up_v];
            }
            return 0;
        }
};

class Solution
{
  public:
  	int detectCycle(int V, vector<int>adj[])
  	{
  	    DisjointSet ds(V);
  	    
  	    for(int i=0;i<V;i++){
  	        for(int j=0;j<adj[i].size();j++){
  	            if(adj[i][j] > i) {
  	                if(ds.unionBySize(i,adj[i][j])) return 1;
  	            }
  	        }
  	    }
  	    return 0;
  	}
};
