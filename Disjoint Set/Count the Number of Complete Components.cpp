Learnings: Disjoint Set, DFS

//M-I:Using DSU to keep track of nodes and edges
//better Time Complexity, though of same order as M-II but less iterations
class Solution {
public:
    vector<int> par, edgeCount, nodeCount;
    int find(int i){
        if(par[i] == -1) return i;
        return find(par[i]);
    }
    
    void unionPair(int a, int b ){
        int pa = find(a), pb = find(b);
        edgeCount[pa] += 1;
        if(pa != pb){
            par[pb] = pa;
            edgeCount[pa] += edgeCount[pb];
            nodeCount[pa] += nodeCount[pb];
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        par.resize(n, -1);   edgeCount.resize(n, 0);    nodeCount.resize(n, 1);
        for(auto e: edges) unionPair(e[0], e[1]);
        for(int i = 0; i < n; ++i){
            if(par[i] == -1  && 
            (nodeCount[i] * (nodeCount[i] - 1)/2 == edgeCount[i])) ans++;
        }
        return ans;
    }
};

//M-II: Counting number od edges and nodes via DFS
class Solution {
public:

    vector<int> dfs(int node,vector<vector<int>>& adj,vector<bool>& vis,int& nodes,int& edges) {
        nodes++;
        // cout<<"node: "<<node<<"  nodes: "<<nodes<<endl;
        vis[node] = true;

        for(int x : adj[node]) {
            edges++;
            if(!vis[x]) {
                dfs(x,adj,vis,nodes,edges);
            }
        }
        vector<int> arr = {nodes,edges};
        return arr;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edg) {
        vector<vector<int>> adj(n);

        for(int i=0;i<edg.size();i++) {
            adj[edg[i][0]].push_back(edg[i][1]);
            adj[edg[i][1]].push_back(edg[i][0]);
        }

        int count = 0;
        int nodes = 0, edges = 0;
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++) {
            if(vis[i] == false) {
                // cout<<"i: "<<i<<"  nodes: "<<nodes<<"  edges: "<<edges<<endl;
                vector<int> arr = dfs(i,adj,vis,nodes,edges);
                nodes = arr[0];
                edges = arr[1]/2;
                // cout<<nodes<<"  "<<edges<<endl;

                if(nodes == 1 || nodes == 2) count++;
                else if(edges == ((nodes-1)*(nodes))/2) count++;
                nodes = 0;edges = 0;
            }
        }
        return count;
    }
};
