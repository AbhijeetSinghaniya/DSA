class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat){
//M-I : B.S. on  rows + L.S. on columns 
        int row = mat.size();        
        if(row == 1){
            int j = max_element(mat[0].begin(),mat[0].end()) - mat[0].begin();
            return {0,j};
        }
        int col = mat[0].size();
        int startrow = 0,endrow = row-1;
        
        while(startrow <= endrow){
            int midrow = (startrow+endrow)/2;            
            int maxelepos = max_element(mat[midrow].begin(),mat[midrow].end()) - mat[midrow].begin();
            
            if(midrow == 0){
                if(mat[midrow][maxelepos] > mat[midrow+1][maxelepos]) return {midrow,maxelepos};
                else return {midrow+1,maxelepos};
            }
            else if(midrow == row-1){
                if(mat[midrow][maxelepos] > mat[midrow-1][maxelepos]) return {midrow,maxelepos};
                else return {midrow-1,maxelepos};
            }
            else if(mat[midrow][maxelepos] > mat[midrow+1][maxelepos] &&
                    mat[midrow][maxelepos] > mat[midrow-1][maxelepos]) return {midrow,maxelepos};
            
            if(mat[midrow][maxelepos] < mat[midrow+1][maxelepos]) startrow = midrow+1;
            else endrow = midrow - 1;
        }
        return {-1,-1}; //dummy return        
       
//M-II : T.C: O(n+m) but won't work in all cases though accepted by LeetCode
//Ex   : [[5,19,11],[16,18,13],[24,17,9]]
        
        int n=mat.size();
        int m=mat[0].size();
        
        int i=0;
        int j=m-1;
        
        while(i<n && j>=0)
        {
            if(isPeak(i,j,n,m,mat))
                return {i,j};
            
            if(i<n-1 && mat[i+1][j]>mat[i][j])
                i++;
            else if(j>0 && mat[i][j-1]>mat[i][j])
                j--;
        }
        
        return {-1,-1};
    }
    
    bool isPeak(int i, int j, int n, int m, vector<vector<int>>& mat)
    {
        int top=i==0?-1:mat[i-1][j];
        int bottom=i==n-1?-1:mat[i+1][j];
        int left=j==0?-1:mat[i][j-1];
        int right=j==m-1?-1:mat[i][j+1];
        
        int k=mat[i][j];
        
        if(k>top && k>bottom && k>left && k>right)
            return true;
        return false;
    }
};