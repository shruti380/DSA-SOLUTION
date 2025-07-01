class Solution {
  public:
    int substrCount(string &s, int k) {
        int l=0;
        int r=0;
        int n=s.size();
        int valid=k-1;
       int  count=0;
       int len=0;
        unordered_map<char,int>mpp;
       
        while(r<n){
            mpp[s[r]]++;
            len=r-l+1;
           while(len>k||mpp.size()>valid){
              
              
               mpp[s[l]]--;
               
               if(mpp[s[l]]==0){
                   mpp.erase(s[l]);
               }
               l++;
              len=r-l+1;
              
               
               
               
           }
           
          
          if(mpp.size()==valid&&len==k){
              count++;
          }
          r++;
          
           
           
        }
        return count;
        
        
    }
};