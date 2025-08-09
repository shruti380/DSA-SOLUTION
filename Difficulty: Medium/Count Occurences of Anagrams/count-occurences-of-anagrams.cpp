// User function template for C++
class Solution {
  public:
  bool allZero(vector<int>&counter){
      for(auto it:counter){
          if(it!=0){
              return false;
          }
      }
      return true;
  }
    int search(string &pat, string &txt) {
       int k=pat.size();
       
       vector<int>counter(26,0);
       for(int i=0;i<pat.length();i++){
           char ch=pat[i];
           counter[ch-'a']++;
           
       }
       int i=0,j=0;
       int n=txt.size();
       int result=0;
       while(j<n){
           int idx=txt[j]-'a';
           counter[idx]--;
           
           
           if(j-i+1==k){
               if(allZero(counter)){
                   result++;
               }
               (counter[txt[i]-'a'])++;
               i++;
           }
           j++;
       }
       return result;
    }
};