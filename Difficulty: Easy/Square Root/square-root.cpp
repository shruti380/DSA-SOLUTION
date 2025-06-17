// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        int ans=-1;
        int low=1;
        int high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid*mid==n){
                return mid;
                break;
                
            }
            else if(mid*mid<=n){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};