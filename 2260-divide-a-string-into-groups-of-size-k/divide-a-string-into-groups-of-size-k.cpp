class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<n;i+=k){
            string s1="";
            for(int j=i;j<=i+k-1&&j<n;j++){
                s1+=s[j];
                
            }
           while(s1.size()<k){
            s1+=fill;
           }
            ans.push_back(s1);
        }
        return ans;
        
    }
};