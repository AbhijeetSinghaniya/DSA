class Solution {
public:
    int timer = 0;
    void dfs(int node,int parent,vector<vector<int>>& adj,vector<int>& vis,vector<int>& inTime,vector<int>& lowTime,vector<vector<int>>& bridges){
        vis[node] = 1;
        inTime[node] = lowTime[node] = timer++;
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,node,adj,vis,inTime,lowTime,bridges);
                lowTime[node] = min(lowTime[node],lowTime[it]);

                if(lowTime[it] > inTime[node]){
                    bridges.push_back({node,it});
                }
            }
            else if(it != parent){
                lowTime[node] = min(lowTime[node],lowTime[it]);
            }    
        }
        return;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto edge : connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> inTime(n,0),lowTime(n,0),vis(n,0);
        vector<vector<int>> bridges;
        
        //Since all the servers are connected, we don't need a loop here
        dfs(0,-1,adj,vis,inTime,lowTime,bridges);
        return bridges;
    }
};
