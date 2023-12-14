#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank,parent,bySize;
    public:
        DisjointSet(int size){
            rank.resize(size+1);
            parent.resize(size+1);
            bySize.resize(size+1);
            for(int i=0;i<=size;i++){
                rank[i] = 0;
                parent[i] = i;
                bySize[i] = 1;
            }
        }
        int getUltimateParent(int node){
            if(parent[node] == node) return node;
            return parent[node] = getUltimateParent(parent[node]);
        }

        //Can use either unionByRank or unionBySize at a time.
        void unionByRank(int u,int v){
            int up_u = getUltimateParent(u); //ultimate parent of u
            int up_v = getUltimateParent(v); //ultimate parent of v
            if(up_u == up_v) return;
            
            if(rank[up_u] < rank[up_v]){
                parent[up_u] = up_v;
            }
            else if(rank[up_u] > rank[up_v]){
                parent[up_v] = up_u;
            }
            else{
                parent[up_v] = up_u;
                rank[up_u]++;
            }
        }

        //Makes more sense because after path compression, height is distorted
        // so rank doesn't make any sense at that point but size will.
        void unionBySize(int u,int v) {
            int up_u = getUltimateParent(u);
            int up_v = getUltimateParent(v);
            if(up_u == up_v) return;
            
            if(bySize[up_u] < bySize[up_v]){
                parent[up_u] = up_v;
                bySize[up_v] += bySize[up_u];
            }
            else{
                parent[up_v] = up_u;
                bySize[up_u] += bySize[up_v];
            }
        }
};
// Time Complexity = O(4α) = constant time (approx)

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
  
    if(ds.getUltimateParent(3) == ds.getUltimateParent(7)){
        cout<<"same"<<endl;
    }
    else cout<<"not same"<<endl;
  
    ds.unionByRank(3,7);
    if(ds.getUltimateParent(3) == ds.getUltimateParent(7)){
        cout<<"same"<<endl;
    }
    else cout<<"not same"<<endl;
}

//output:
// not same
// same







