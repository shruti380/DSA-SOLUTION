class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int l=0;
        int r=0;
        int n= s.size();
        int len=0;
        int maxLen=-1e9;
        unordered_map<char,int>mpp;
        while(r<n){
            mpp[s[r]]++;
            len=r-l+1;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
                len=r-l+1;
            }
            if(mpp.size()==k){
            maxLen=max(maxLen,len);
            }
            r++;
        }
        if(mpp.size()==k){
            return maxLen;
        }
        return -1;
        
        
        
    }
};