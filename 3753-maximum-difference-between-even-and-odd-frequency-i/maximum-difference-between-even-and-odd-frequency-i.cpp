class Solution {
public:
    int maxDifference(string s) {
        int ans=INT_MIN;
        int n=s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
       vector<int>evenFreq,oddFreq;
       for(auto it:mpp){
        if(it.second%2==0){
            evenFreq.push_back(it.second);
        }
        else{
            oddFreq.push_back(it.second);
        }
       }
       if (oddFreq.empty() || evenFreq.empty()) return -1;
       for(int i=0;i<oddFreq.size();i++){
        for(int j=0;j<evenFreq.size();j++){
            ans=max(ans,(oddFreq[i]-evenFreq[j]));
        }
       }
       return ans;
    }
};