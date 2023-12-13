
//Kahn's Algorithm
public:
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto x : adj[i]){
                indegree[x]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++) if(indegree[i] == 0) q.push(i);
        
        int cnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
          
            for(auto curr : adj[node]){
                indegree[curr]--;
                if(indegree[curr] == 0) q.push(curr);
            }
        }
        
        if(cnt == V) return false;
        else return true;
    }
};
