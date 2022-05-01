class Solution {
public:
    
    bool isValid(int i,int j,int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
        
        if(i < 0 || j < 0 || i >= row || j >= col || vis[i][j] == 1 || grid[i][j] == -1) //never check last 2-conditions before first 4-condiitions
            return false;
        return true;
    }
    
    void dfs(int i,int j,int x,int y,int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis, int &ans,int cnt,int ecells){
     
        if(i == x && j == y){
            if(cnt-1 == ecells) ans++;
            return;
        }
        int di[] = {0,0,+1,-1};
        int dj[] = {+1,-1,0,0};
        
        for(int k=0;k<4;k++){
            if(isValid(i+di[k],j+dj[k],row,col,grid,vis)){
                vis[i+di[k]][j+dj[k]] = 1;
                dfs(i+di[k],j+dj[k],x,y,row,col,grid,vis,ans,cnt+1,ecells);
                vis[i+di[k]][j+dj[k]] = 0;
            }                                                 
        }        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0,starti,startj,endi,endj,ecells = 0;
        
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 1){
                    starti = i;
                    startj = j;
                }
                if(grid[i][j] == 2){
                    endi = i;
                    endj = j;
                }
                if(grid[i][j] == 0) ecells++;
            }
        }
      
        vector<vector<int>> vis(row,vector<int> (col,0));
        vis[starti][startj] = 1;
      
        dfs(starti,startj,endi,endj,row,col,grid,vis,ans,0,ecells); 
        return ans;
    }
};

//Optimized Code : No need for visited and endi & endj

class Solution {
public:
    int res = 0, empty = 1;
    void dfs(vector<vector<int>>& grid, int x, int y, int count) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == -1) return;
        
        if (grid[x][y] == 2) {
            if(empty == count) res++; 
            return;
        }
        
        grid[x][y] = -1;
        
        dfs(grid, x+1, y, count+1);
        dfs(grid, x-1, y, count+1);
        dfs(grid, x, y+1, count+1);
        dfs(grid, x, y-1, count+1);
        
        grid[x][y] = 0;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x, start_y;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) start_x = i, start_y = j;
                else if (grid[i][j] == 0) empty++;
            }
        }
        
        dfs(grid, start_x, start_y, 0);
        return res;
    }
};
