class Solution {
public:


    int smallestDivisor(vector<int>& nums, int threshold) {
       
        int n=nums.size();
        
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
           
            maxi=max(maxi,nums[i]);
        }
        int low=1;
        int high=maxi;
        while(low<=high){
            int ans=0;
            int mid=low+(high-low)/2;
            for(int i=0;i<n;i++){
                ans+=ceil((double)nums[i]/mid);
                }
                if(ans<=threshold){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }


        }
        return low;
    }
};