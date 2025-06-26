class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int len=0;
        long long powerVal=1;
        for(int i=s.size()-1;i>=0;--i){
            if(s[i]=='0'){
            len++;
            }else if(powerVal<=k){
                len++;
                k-=powerVal;
            }
            if(powerVal<=k){
                powerVal*=2;
            }
        }
        return len;

    }
};