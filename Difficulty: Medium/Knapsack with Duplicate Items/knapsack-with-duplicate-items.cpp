// User function Template for C++

class Solution {
  public:
  int maxValue(int ind,vector<int>& val,vector<int>& wt,int capacity,vector<vector<int>>&dp){
      if(ind==0){
          return ((capacity/wt[0])*val[0]);
      }
      if(dp[ind][capacity]!=-1){
          return dp[ind][capacity];
      }
      int notTake=0+maxValue(ind-1,val,wt,capacity,dp);
      int take=0;
      if(wt[ind]<=capacity){
          take=val[ind]+maxValue(ind,val,wt,capacity-wt[ind],dp);
      }
      return dp[ind][capacity]=max(take,notTake);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return maxValue(n-1,val,wt,capacity,dp);
        
    }
};