class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& arr) {
        
        int m = arr.size();
        int n = arr[0].size();
        
        int t[m][n];
        
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 && j == n-1){
                    t[i][j] = min(arr[i][j],0);
                }
                
                else if(i == m-1){
                    t[i][j] = min(t[i][j+1] + arr[i][j],0);
                }
                
                else if(j == n-1){
                    t[i][j] = min(t[i+1][j] + arr[i][j],0);
                }
                
                else{
                    t[i][j] = min(max(t[i+1][j],t[i][j+1]) + arr[i][j],0);
                }
            }
        }
        return abs(t[0][0]) + 1;
    }
};
