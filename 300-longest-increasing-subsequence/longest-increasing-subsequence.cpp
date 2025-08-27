class Solution {
public:
int solve(int ind,int prev,vector<int>&nums,vector<vector<int>>&dp,int n){
    if(ind==n){
        return 0;
    }
    if(dp[ind][prev+1]!=-1){
        return dp[ind][prev+1];
    }
    int notake=0+solve(ind+1,prev,nums,dp,n);
    int take=0;
    if(prev==-1||nums[prev]<nums[ind]){
    take=1+solve(ind+1,ind,nums,dp,n);
    }
    return dp[ind][prev+1]=max(take,notake);

}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp,n);
        
        
    }
};