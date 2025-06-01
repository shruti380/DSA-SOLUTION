class Solution {
public:
int lcs(int i,int j,string &text1,string&text2,vector<vector<int>>&dp){
    if(i<0||j<0) return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    if(text1[i]==text2[j]){
        return dp[i][j]=1+lcs(i-1,j-1,text1,text2,dp);
    }
    return dp[i][j]=0+max(lcs(i,j-1,text1,text2,dp),lcs(i-1,j,text1,text2,dp));
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                   if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                   }
                   else{
                     dp[i][j]=0+max(dp[i][j-1],dp[i-1][j]);
                   }
            }
        }
        int result= dp[n][m];
        if(result==-1){
            return 0;
        }
        return result;
        
    }
};