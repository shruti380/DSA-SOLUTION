class Solution {
  public:
  int maxPath(int row,int col,vector<vector<int>>&mat,vector<vector<int>>&dp){
      int n=mat.size();
      int m=mat[0].size();
      
      if(col==m-1){
          return mat[row][col];
      }
      if (dp[row][col] != -1) {
            return dp[row][col];
        }
      
      int maxVal=0;
      if(row>0){
          maxVal=max(maxVal,maxPath(row-1,col+1,mat,dp));
      }
      maxVal=max(maxVal,maxPath(row,col+1,mat,dp));
      if(row<n-1){
          maxVal=max(maxVal,maxPath(row+1,col+1,mat,dp));
      }
      return dp[row][col]=mat[row][col]+maxVal;
  }
  
    int maxGold(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxResult=0;
        for(int i=0;i<n;i++){
            maxResult=max(maxResult,maxPath(i,0,mat,dp));
        }
        return maxResult;
       
        
    }
};