class Solution {
public:
    int trap(vector<int>& height) {
//M-I(BEST APPROACH)
        int res = 0,lmax=0,rmax=0;
        int l=0,r=height.size()-1;
        
        while(l < r){
            if(height[l] <= height[r]){
                if(height[l] >= lmax) lmax = height[l];
                else res += lmax - height[l];
                l++;
            }
            else{
                if(height[r] >= rmax) rmax = height[r];
                else res += rmax - height[r];
                r--;
            }
        }
        return res; 
//M-II(SECOND BEST APPROACH)  
        
        int n = height.size(),ans = 0;
        vector<int>left(n),right(n);
        
        left[0] = height[0];right[n-1] = height[n-1];
        
        for(int i=1;i<n;i++) left[i] = max(left[i-1],height[i]);
        for(int i=n-2;i>=0;i--) right[i] = max(right[i+1],height[i]);
        for(int i=0;i<n;i++) ans += min(left[i],right[i])-height[i];
        
        return ans;
    }
};
