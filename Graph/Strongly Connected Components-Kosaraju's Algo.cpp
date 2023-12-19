class Solution
{
    // Pass adj by reference to avoid TLE
    void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,stack<int>& st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    }

    // Pass adj by reference to avoid TLE
    void dfsT(int node,vector<vector<int>>& adjT,vector<int>& vis){
        vis[node] = 1;
        for(auto it : adjT[node]){
            if(!vis[it]){
                dfsT(it,adjT,vis);
            }
        }
    }
    
	public:
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs(i,adj,vis,st);
        }
        
        vector<vector<int>> adjT(V);
        
        for(int i=0;i<V;i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                // i -> it TO it -> i
                adjT[it].push_back(i);
            }
        }
        
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfsT(node,adjT,vis);
            }
        }
        return scc;
    }
};
