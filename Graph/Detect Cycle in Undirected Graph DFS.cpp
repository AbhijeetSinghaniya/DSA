class Solution {
  public:
    bool dfs(int node,vector<int> adj[],vector<int>& vis,int parent){
        if(vis[node]) return false;        
        vis[node] = 1;
        
        for(auto x : adj[node]){
            if(vis[x]){
                if(x == parent) continue;
            }
            else{
                return true;
            } 
            if(dfs(x,adj,vis,node)){
                return true;
            }
        } 
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0); 
        for(int i=0;i<V;i++){
            if(dfs(i,adj,vis,-1)) return true;
        }
        return false;
    }
};
