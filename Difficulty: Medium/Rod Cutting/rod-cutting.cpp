// User function Template for C++

class Solution {
  public:
  
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        for(int N=0;N<=n;N++){
            dp[0][N]=N*price[0];
        }
        for(int ind =1;ind<n;ind++){
            for(int N=0;N<=n;N++){
                int notTake=0+dp[ind-1][N];
                int take=INT_MIN;
                int rodLength=ind+1;
                if(rodLength<=N){
                    take=price[ind]+dp[ind][N-rodLength];
                }
                dp[ind][N]=max(take,notTake);
                
            }
        }
        return dp[n-1][n];
        
    }
};