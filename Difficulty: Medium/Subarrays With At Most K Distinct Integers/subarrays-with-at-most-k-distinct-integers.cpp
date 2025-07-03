class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int l=0;
        int r=0;
        int n=arr.size();
        int count=0;
        unordered_map<int,int>mpp;
    
        while(r<n){
            mpp[arr[r]]++;
            while(mpp.size()>k){
                mpp[arr[l]]--;
                if(mpp[arr[l]]==0){
                    mpp.erase(arr[l]);
                }
                l++;
            }
           
            if(mpp.size()<=k){
                count+=r-l+1;
            }
            r++;
        }
        return count;
    }
};