class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n=prices.size();
        int profit;
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy==0){
                        profit=max(0+dp[ind+1][0][cap],-prices[ind]+dp[ind+1][1][cap]);
                    }
                    if(buy==1){
                        profit=max(0+dp[ind+1][1][cap],prices[ind]+dp[ind+1][0][cap-1]);
                    }
                    dp[ind][buy][cap]=profit;
                }
            }
        }
        return dp[0][0][k];

        
    }
};