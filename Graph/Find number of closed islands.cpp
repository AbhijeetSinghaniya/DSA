class Solution {
    bool isValid(int x,int y,int row,int col,vector<vector<int>>& mat){
        return x>=0 && x<row && y>=0 && y<col && mat[x][y] == 1;
    }
    
    bool dfs(int x,int y,vector<vector<int>>& mat,int row,int col,int& flag){
        mat[x][y] = 2;
        
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int newr = x + dx[i];
            int newc = y + dy[i];
            
            if(isValid(newr,newc,row,col,mat)){
                if(newr == 0 || newc == 0 || newr == row-1 || newc == col-1) flag = 1;
                dfs(newr,newc,mat,row,col,flag);
            }
        }
        if(flag == 0) return true;
        else return false;
    }
    
    public:
    int closedIslands(vector<vector<int>>& mat, int row, int col) {
        int ans = 0;
        for(int i=1;i<row-1;i++){
            for(int j=1;j<col-1;j++){
                if(mat[i][j] == 1){
                    int flag = 0;
                    if(dfs(i,j,mat,row,col,flag)) ans++;
                }
            }
        }
        return ans;
    }
};
