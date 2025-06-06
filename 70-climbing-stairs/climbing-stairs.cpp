class Solution {
public:
int memo(int ind,vector<int>&dp){
    if(ind==0||ind==1){
        return 1;
    }
    if(dp[ind]!=-1)return dp[ind];
    return dp[ind]=memo(ind-1,dp)+memo(ind-2,dp);
    
}
    int climbStairs(int n) {
    
        int prev2=1;
        int prev=1;
        for(int i=2;i<=n;i++){
            int cur=prev2+prev;
            prev2=prev;
            prev=cur;
        }
        return prev;
    }
};