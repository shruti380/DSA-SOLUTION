class Solution {
public:
int longest(string&text1, string&text2,int ind1,int ind2,int n,int m,vector<vector<int>>&dp){
    if(ind1<0||ind2<0){
        return 0;
    }
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    if(text1[ind1]==text2[ind2]){
        return dp[ind1][ind2]=1+longest(text1,text2,ind1-1,ind2-1,n,m,dp);
    }
    else{
        return dp[ind1][ind2]=max(longest(text1,text2,ind1-1,ind2,n,m,dp),longest(text1,text2,ind1,ind2-1,n,m,dp));
    }
}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return longest(text1,text2,n-1,m-1,n,m,dp);
        
    }
};