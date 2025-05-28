class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n =arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1));
       if(arr[0]==0)dp[0][0]=2;
       else dp[0][0]=1;
       if(arr[0]!=0&&arr[0]<=target)dp[0][arr[0]]=1;
       
        
        for(int i=1;i<n;i++){
            for(int s=0;s<=target;s++){
                int notPick=dp[i-1][s];
                int pick=0;
                if(arr[i]<=s){
                    pick=dp[i-1][s-arr[i]];
                }
                dp[i][s]=pick+notPick;
            }
        }
        return dp[n-1][target];
    }
};