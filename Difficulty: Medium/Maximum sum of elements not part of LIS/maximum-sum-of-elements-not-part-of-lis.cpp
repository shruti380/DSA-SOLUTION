class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
       int n = arr.size();
       int total=accumulate(arr.begin(),arr.end(),0);
       int maxLis=1;
       int minLisSum=arr[0];
       
       vector<int>dp(n,1);
       vector<int>dpMinSum(n);
       
       for(int i=0;i<n;i++){
           dpMinSum[i]=arr[i];
           
       }
       for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
               if(arr[i]>arr[j]){
                   int currLen=dp[j]+1;
                   int currSum=dpMinSum[j]+arr[i];
                   
                   if(currLen>dp[i]){
                       dp[i]=currLen;
                       dpMinSum[i]=currSum;
                   }
                   else if(currLen==dp[i]){
                       dpMinSum[i]=min(dpMinSum[i],currSum);
                   }
               }
           }
           if(dp[i]>maxLis){
               maxLis=dp[i];
               minLisSum=dpMinSum[i];
           }
           else if(dp[i]==maxLis){
               minLisSum=min(minLisSum,dpMinSum[i]);
           }
           
       }
       return total-minLisSum;
    }
};