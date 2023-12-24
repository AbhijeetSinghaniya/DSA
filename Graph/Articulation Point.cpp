//Pre-Requisite : Critical Connections in a Network

class Solution {
    int timer = 0;
    void dfs(int node,int parent,vector<int> adj[],vector<int>& vis,vector<int>& inTime,
    vector<int>& lowTime,vector<int>& mark){
        
        vis[node] = 1;
        inTime[node] = lowTime[node] = timer++;
        int child = 0;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,node,adj,vis,inTime,lowTime,mark);
                lowTime[node] = min(lowTime[node], lowTime[it]);
                
                if(lowTime[it] >= inTime[node] && parent != -1){
                    mark[node] = 1;
                }
                child++;
            }
            else if(it != parent){
                lowTime[node] = min(lowTime[node],inTime[it]);
            }
        }
        if(parent == -1 && child > 1) mark[node] = 1;
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<int> vis(V,0),inTime(V,0),lowTime(V,0),mark(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,adj,vis,inTime,lowTime,mark);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i] == 1) ans.push_back(i);
        }
        
        if(ans.size() == 0) return {-1};
        else return ans;
    }
};
