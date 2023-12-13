class Solution {
  public:
    bool bfs(int node,int parent,vector<int>& vis, vector<int> adj[]){
        vis[node] = 1;
        queue<pair<int,int>> q;
        q.push({node,parent});
        
        while(!q.empty()){
            int curr = q.front().first;
            int par = q.front().second;
            q.pop();
            
            for(auto x : adj[curr]){
                if(!vis[x]){
                    q.push({x,curr});
                    vis[x] = 1;
                }
                else if(x != par) return true;
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(vis[i] == 0) {
                if(bfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};
