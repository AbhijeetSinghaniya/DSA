//Learnings: Topo Sort, 2D-matrix, correlating multiple arrays(1D, 2D) with different starting index

class Solution {
public:
    bool topoSort(queue<int> q,vector<int>& indegree,vector<int>& sorted,
                vector<vector<int>>& adj) {
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            sorted.push_back(node);

            for(auto curr : adj[node]){
                if(--indegree[curr] == 0) {
                    q.push(curr);
                }
            }
        }

        for(auto val : indegree) {
            if(val != 0) return false;
        }
        return true;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowCond, 
    vector<vector<int>>& colCond) {
        vector<vector<int>> rowAdj(k+1), colAdj(k+1);
        vector<int> rowIndegree(k+1, 0), colIndegree(k+1, 0);
        
        for(int i=0;i<rowCond.size();i++) {
            rowAdj[rowCond[i][1]].push_back(rowCond[i][0]);
            rowIndegree[rowCond[i][0]]++;
        }
        
        for(int i=0;i<colCond.size();i++) {
            colAdj[colCond[i][1]].push_back(colCond[i][0]);
            colIndegree[colCond[i][0]]++;
        }

        vector<vector<int>> ans;
        
        queue<int> rowQ;
        for(int i=1;i<=k;i++) {
            if(rowIndegree[i] == 0) rowQ.push(i);
        }

        vector<int> rowSort;
        //Getting values for rows from bottom to top
        if(!topoSort(rowQ,rowIndegree,rowSort,rowAdj)) return ans;

        queue<int> colQ;
        for(int i=1;i<=k;i++) {
            if(colIndegree[i] == 0) colQ.push(i);
        }
      
        vector<int> colSort;
        //Getting values for columns from right to left
        if(!topoSort(colQ, colIndegree,colSort,colAdj)) return ans;
        
        vector<vector<int>> coordinates(k+1, vector<int> (2,-1));
        
        int counter = k-1;
        //Assigning row to values
        for(int i=0;i<k;i++) {
            coordinates[rowSort[i]][0] = counter--;
        }
        
        counter = k-1;
        //Assigning column to values
        for(int i=0;i<k;i++) {
            coordinates[colSort[i]][1] = counter--;
        }

        ans.resize(k, vector<int> (k,0));
        for(int i=1;i<=k;i++) {
            ans[coordinates[i][0]][coordinates[i][1]] = i;
        }

        return ans;
    }
};
