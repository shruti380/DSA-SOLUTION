class Solution {
public:
bool check(string s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void solve(string s,vector<string>&ds,vector<vector<string>>&ans,int ind){
    if(ind==s.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<s.size();i++){
        if(check(s,ind,i)){
            ds.push_back(s.substr(ind,i-ind+1));
            solve(s,ds,ans,i+1);
            ds.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        vector<vector<string>>ans;
        solve(s,ds,ans,0);
        return ans;
        
    }
};