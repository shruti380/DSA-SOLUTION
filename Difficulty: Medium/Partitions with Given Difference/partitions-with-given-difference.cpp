class Solution {
  public:
    int countPartitions(vector<int>& arr, int d) {
        int mod=1e9+7;
        int n=arr.size();
        int tSum=0;
        for(int i=0;i<n;i++){
            tSum+=arr[i];
        }
        if ((tSum +d) % 2 != 0 || tSum- d<0) return 0;
        int target=(tSum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(arr[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        if(arr[0]!=0&&arr[0]<=target){
            dp[0][arr[0]]=(dp[0][arr[0]] + 1) % mod;;
        }
        for(int i=1;i<n;i++){
            for(int s=0;s<=target;s++){
                int notTake=dp[i-1][s];
                int take=0;
                if(arr[i]<=s){
                    take=dp[i-1][s-arr[i]];
                }
                dp[i][s]=(take+notTake)%mod;
            }
        }
        return dp[n-1][target];
        
    }
};