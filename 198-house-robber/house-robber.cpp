class Solution {
public:
int memo(int ind,vector<int>&nums,vector<int>&dp){
    if(ind==0)return nums[ind];
    if(ind<0)return 0;
    if(dp[ind]!=-1)return dp[ind];
    int notTake=0+memo(ind-1,nums,dp);
    
    
      int    take=nums[ind]+memo(ind-2,nums,dp);
    
    return dp[ind]=max(take,notTake);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return memo(n-1,nums,dp);
        
    }
};