class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(2,0);
        vector<int>curr(2,0);
        int profit;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy==0){
                profit=max(ahead[0]+0,-prices[ind]+ahead[1]);
                }
                if(buy==1){
                    profit=max(ahead[1]+0,prices[ind]+ahead[0]);
                }
                curr[buy]=profit;
            }
            ahead=curr;
        }
        return curr[0];
                
        
        
    }
};