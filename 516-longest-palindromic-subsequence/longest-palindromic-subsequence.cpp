class Solution {
public:
int longest(string&text1, string&text2,int ind1,int ind2,int n,vector<vector<int>>&dp){
    if(ind1<0||ind2<0){
        return 0;
    }
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    if(text1[ind1]==text2[ind2]){
        return dp[ind1][ind2]=1+longest(text1,text2,ind1-1,ind2-1,n,dp);
    }
    else{
        return dp[ind1][ind2]=max(longest(text1,text2,ind1-1,ind2,n,dp),longest(text1,text2,ind1,ind2-1,n,dp));
    }
}
    int longestPalindromeSubseq(string text1) {
        string text2=text1;
        reverse(text2.begin(),text2.end());
        int n=text1.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return longest(text1,text2,n-1,n-1,n,dp);
        
        
    }
};