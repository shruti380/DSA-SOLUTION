class Solution {
  public:
  int pow(int x,int y){
      int ans=1;
      while(y){
          if(y%2==1){
              ans=ans*x;
              y=y-1;
              
          }
          else{
              x=x*x;
              y/=2;
          }
          
          
          
      }
      return ans;
  }
    int nthRoot(int n, int m) {
        // Code here.
        int low=1;
        int high=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(pow(mid,n)==m){
                return mid;
                break;
            }
            else if(pow(mid,n)<=m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};