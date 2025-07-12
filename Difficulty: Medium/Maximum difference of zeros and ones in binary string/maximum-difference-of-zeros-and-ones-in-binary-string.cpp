// User function template for C++
class Solution {
  public:
    int maxSubstring(string S) {
        int cnt=0;
        int maxi=-1;
        for(int i=0;i<S.size();i++){
            if(S[i]=='0'){
                cnt++;
                maxi=max(maxi,cnt);
                
            }
            else if(S[i]=='1'){
                cnt--;
            }
            if(cnt<0)cnt=0;
        }
        return maxi;
    }
};