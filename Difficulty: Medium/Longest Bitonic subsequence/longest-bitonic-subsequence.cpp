
class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        for(int i=0;i<n;i++){
            for(int prevIndex=0;prevIndex<i;prevIndex++){
                if(nums[prevIndex]<nums[i]){
                    dp1[i]=max(dp1[i],1+dp1[prevIndex]);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int prevIndex=n-1;prevIndex>i;prevIndex--){
                if(nums[prevIndex]<nums[i]){
                    dp2[i]=max(dp2[i],1+dp2[prevIndex]);
                }
            }
        }
        int maxi=0;
        
        for(int i=0;i<n;i++){
            if(dp1[i]>1&&dp2[i]>1){
            maxi=max(maxi,dp1[i]+dp2[i]-1);
            }
        }
        return maxi;
    }
};
