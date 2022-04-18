class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row = mat.size();
        int col = mat[0].size();
        
        int i=0,j=col-1;
        while(i < row && j >= 0){
            if(mat[i][j] == target) return true;
            
            else if(mat[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};
