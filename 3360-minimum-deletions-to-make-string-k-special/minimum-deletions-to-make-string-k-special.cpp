class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26,0);
        int result=word.length();
        for(int i=0;i<word.size();i++){
            freq[word[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            int del=0;
            for(int j=0;j<26;j++){
                if(i==j)continue;
                 if(freq[j] < freq[i]) {
                    del += freq[j];
                 }
                else if(abs(freq[j]-freq[i])>k){
                    del+=(freq[j]-freq[i]-k);
                }
                }
                 result=min(del,result);
               
            }
           
        
        return result;
        
        
    }
};