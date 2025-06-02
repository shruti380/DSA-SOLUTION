class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n=arr.size();
        // code here
        int sum=0;
        int maxlen=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        
        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        int rem=sum-k;
        if(mpp.find(rem)!=mpp.end()){
            int len=i-mpp[rem];
            maxlen=max(maxlen,len);
        }
        if(mpp.find(sum)==mpp.end()){
            mpp[sum]=i;
        }
        
        }
        return maxlen;
    }
};