class Solution {
  public:
  void recursion(vector<int>&arr,vector<int>&ans,int ind,int n,int sum){
      if(ind>=n){
          ans.push_back(sum);
          return;
      }
      recursion(arr,ans,ind+1,n,sum);
      if(ind<n){
          recursion(arr,ans,ind+1,n,sum+arr[ind]);
      }
  }
    vector<int> subsetSums(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans;
        int sum=0;
        recursion(arr,ans,0,n,sum);
        return ans;
        
    }
};