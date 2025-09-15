class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int rem=sum-x;
        int sum1=0;
        int len=-1e9;
        while(r<n){
            sum1+=nums[r];
            while(sum1>rem&&l<=r){
                sum1-=nums[l];
                l++;
            }
            if(sum1==rem){
            len=max(len,r-l+1);
           
            }
            r++;
            
            
        }
        if(len==-1e9){
            return -1;
        }
        return n-len;
        
    }
};