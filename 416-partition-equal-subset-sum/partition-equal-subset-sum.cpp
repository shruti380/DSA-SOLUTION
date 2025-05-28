class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=nums[i];
        }
        if(totalSum%2!=0){
            return false;
        }
        else{
            int k=totalSum/2;
            vector<vector<bool>>dp(n,vector<bool>(k+1));
            for(int i=0;i<n;i++){
                dp[i][0]=true;
            }
            if(nums[0]<=k){
                dp[0][nums[0]]=true;
            }
            for(int i=1;i<n;i++){
                for(int sum=1;sum<=k;sum++){
                    bool notTaken=dp[i-1][sum];
                    bool taken=false;
                    if(nums[i]<=sum){
                        taken=dp[i-1][sum-nums[i]];
                    }
                    dp[i][sum]=notTaken||taken;
                }
            }
            return dp[n-1][k];
        }
        
        
        
    }
};