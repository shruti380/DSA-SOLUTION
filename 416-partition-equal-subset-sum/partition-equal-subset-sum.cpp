class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int k=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k){
            dp[0][nums[0]]=true;
        }
        for(int ind=1;ind<n;ind++){
            for(int j=1;j<=k;j++){
                bool notTaken=dp[ind-1][j];
                bool taken=false;
                if(nums[ind]<=j){
                    taken=dp[ind-1][j-nums[ind]];
                }
                dp[ind][j]=taken||notTaken;

            }

        }
        return dp[n-1][k];
    }
};