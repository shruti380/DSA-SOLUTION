class Solution {
public:
int miniCoins(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[0]==0){
              return  ( amount/coins[0]);
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int notTake=0+miniCoins(ind-1,coins,amount,dp);
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+miniCoins(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(take,notTake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int result= miniCoins(n-1,coins,amount,dp);
        if(result>=1e9){
            return -1;
        }
        return result;
        
    }
};