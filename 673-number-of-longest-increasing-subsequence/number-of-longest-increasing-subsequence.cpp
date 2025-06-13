class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>ct(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int prevIndex=0;prevIndex<i;prevIndex++){
                if(nums[prevIndex]<nums[i]&&dp[prevIndex]+1>dp[i]){
                    dp[i]=dp[prevIndex]+1;
                    ct[i]=ct[prevIndex];
                }
                else if(nums[prevIndex]<nums[i]&&dp[prevIndex]+1==dp[i]){
                    ct[i]=ct[i]+ct[prevIndex];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int noLis=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                noLis+=ct[i];
            }
        }
        return noLis;
        
    }
};