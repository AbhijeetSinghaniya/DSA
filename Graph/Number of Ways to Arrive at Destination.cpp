//Learnings: Dijkstra Algorithm, integer overflow(make changes everywhere when using long long), modulo

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int modulo = 1e9 + 7;
        typedef long long ll;

        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<roads.size();i++) {
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }

        vector<pair<ll,int>> disTo(n,std::make_pair(LLONG_MAX, 0));
        set<pair<ll,int>> s;
        s.insert({0,0});
        disTo[0] = {0,1};

        while(!s.empty()) {
            auto it = *(s.begin());
            int node = it.second;
            ll dist = it.first;
            s.erase(it);

            for(int i=0;i<adj[node].size();i++) {
                int adjNode = adj[node][i].first;
                int edgeWeight = adj[node][i].second;
                
                ll totalWeight = (ll)dist + edgeWeight;
                if(totalWeight < disTo[adjNode].first) {
                    if(disTo[adjNode].first != LLONG_MAX) {
                        s.erase({disTo[adjNode].first,disTo[adjNode].second});
                    }

                    disTo[adjNode] = {totalWeight,disTo[node].second%modulo};
                    s.insert({totalWeight, adjNode});
                }
                else if(totalWeight == disTo[adjNode].first) {
                    ll totalWays = ((ll)disTo[adjNode].second + (ll)disTo[node].second)%modulo;
                    disTo[adjNode] = {disTo[adjNode].first,totalWays};
                    // s.insert({disTo[adjNode].first, adjNode}); //No need as we already have one entry in set
                }
            }
        }
        return disTo[n-1].second;
    }
};
