class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n),back(n);
        
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            back[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        int ans = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node] = 1;
            
            for(auto curr : adj[node]){
                if(vis[curr] == 0){
                    q.push(curr);
                    ans++;
                }
            }            
            for(auto curr : back[node]){
                if(vis[curr] == 0){
                    q.push(curr);
                }
            }
        }
        return ans;
    }
};
