class Solution {
  public:
  bool check(int sum,int i,int n,vector<int>& b,int k){
         if(sum>k)return false;
         if(sum==k)return true;
         if(sum<k && i==n)return false;
         return check(sum+b[i],i+1,n,b,k) || check(sum,i+1,n,b,k);
     }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return check(0,0,n,arr,k);
    }
};