class Solution {
  public:
    bool dfs_cyclic(int node,vector<int> adj[],vector<int>& vis,vector<int>& order){
        vis[node] = 1;
        order[node] = 1; 
      
        for(auto curr : adj[node]){
            if(!vis[curr]){
                if(dfs(curr,adj,vis,order)) return true;
            }
            else if(order[curr]) return true;
        }
        order[node] = 0;
        return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0),order(V,0);        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,order)) return true;;
            }
        }
        return false;
    }
};
