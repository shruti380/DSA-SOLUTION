class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int countEven=0;
        int countOdd=0;
        for(int num:nums){
            if(num%2==0){
                countEven++;
            }
            else{
                countOdd++;
            }
        }
        int alternating=1;
        int current=nums[0]%2;
        for(int i=1;i<n;i++){
              int nextP=nums[i]%2;
              if(nextP!=current){
                alternating++;
                current=nextP;
              }
        }
        return max(countEven,max(countOdd,alternating));
        
    }
};