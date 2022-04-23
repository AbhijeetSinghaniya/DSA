#include<bits/stdc++.h>
class Solution {
public:   
    bool dfs(int node,int par,vector<int>& vis,vector<int> graph[],vector<int>& ans){
        vis[node] = 1;
        
        for(auto curr : graph[node]){
            if(vis[curr] == 0){
                ans.push_back(curr);
                if(dfs(curr,node,vis,graph,ans)) return true;
                ans.pop_back();
            }
            else if(curr != par){
                ans.push_back(curr);
                return true;
            }
        }
        return false;
    }    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> graph[n+1],vis(n+1,0),ans;
        
        for(auto it : edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
              
        for(int i=1;i<=n;i++){
            if(vis[i] == 0){
                ans.push_back(i);
                if(dfs(i,-1,vis,graph,ans)) break; //if cycle is found
                ans.pop_back(); //backtrack if no cycle is found
            }
        }
        
        int m = ans.size();
        unordered_set<int> us;
        us.insert(ans[m-1]);
        for(int i = m-2;i>=0;i--){
            if(ans[i] == ans[m-1]) break; //Ex:[[1,2],[2,3],[3,4],[2,4],[1,5]]
            us.insert(ans[i]);
        }
        
        for(int i=n-1;i>=0;i--){
            if(us.count(edges[i][0]) && us.count(edges[i][1])){ //checking last valid ans input
                return edges[i]; //Actual ans
            }
        }
        return vis; //dummy return
    }
};
