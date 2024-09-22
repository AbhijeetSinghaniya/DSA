class Solution {
	public:
	int maxSumIS(int arr[], int n)  {  
	    vector<int> dp(n);
	    for(int i=0;i<n;i++) dp[i] = arr[i];
	    int ans = arr[0];
	    
	    for(int i=1;i<n;i++){
	        for(int j=i-1;j>=0;j--){
	            if(arr[j] < arr[i])
	                dp[i] = max(dp[i], dp[j]+arr[i]);
	        }
	        ans = max(ans,dp[i]);
	    }
	    return ans;
	}  
};
