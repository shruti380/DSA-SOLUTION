class Solution {
  public:
  static bool cmp(string a,string b){
      if(a.length()!=b.length()){
          return a.length()<b.length();
      }
      return a>b;
  }
    string longestString(vector<string> &arr) {
        // code here
        unordered_map<string, int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        sort(arr.begin(),arr.end(),cmp);
        for(int i=n-1;i>=0;i--){
            int l=arr[i].length();
            bool ye=true;
            string t="";
            for(int k=0;k<l;k++){
                t+=arr[i][k];
                if(mp[t]==0){
                    ye=false;
                    break;
                }
                if(ye){
                    return arr[i];
                }
            }
        }
        return "";
        
    }
};