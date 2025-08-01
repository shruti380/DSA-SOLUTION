class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
       vector<int> hash(n);
      for (int i = 0; i < n; i++) {
         hash[i] = i;
}
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prevIndex=0;prevIndex<i;prevIndex++){
                if(nums[i]%nums[prevIndex]==0&&1+dp[prevIndex]>dp[i]){
                    dp[i]=1+dp[prevIndex];
                    hash[i]=prevIndex;
                }
            }
        }
        int ans=-1;
        int lastIndex=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastIndex=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};