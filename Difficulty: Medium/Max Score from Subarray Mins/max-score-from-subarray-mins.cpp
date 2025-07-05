class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int maxSum=-1e9;
        for(int i=0;i<arr.size()-1;i++){
            maxSum=max(maxSum,arr[i]+arr[i+1]);
        }
        return maxSum;
    }
};