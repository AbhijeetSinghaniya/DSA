//Learnings: identify that a cycle(in directed graph) needs to be checked for answer

class Solution {
public:

    bool isDirectedGraphCyclic(int node,vector<vector<int>>& adj,
    vector<bool>& vis,vector<bool>& order) {
        vis[node] = true;
        order[node] = true;

        for(auto curr : adj[node]) {
            // cout<<vis[curr]<<order[curr]<<endl;
            if(!vis[curr]) {
                if(isDirectedGraphCyclic(curr,adj,vis,order)) return true;
            }
            else if(order[curr]) {
                // cout<<"returning true"<<endl;
                return true;
            }
        }
        order[node] = false;
        return false;
    }

    bool canFinish(int numc, vector<vector<int>>& prq) {
        vector<vector<int>> adj(numc);

        for(int i=0;i<prq.size();i++) {
            adj[prq[i][0]].push_back(prq[i][1]);
        }

        vector<bool> vis(numc,false), order(numc, false);
        for(int i=0;i<numc;i++) {
            if(!vis[i]) {
                if(isDirectedGraphCyclic(i,adj,vis,order)) return false;
            }
        }

        return true;
    }
};
