class Solution {
public:
void solve(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>&ds,int ind){
          if(target==0){
            ans.push_back(ds);
            return ;
}
            
          

          

for(int i=ind;i<candidates.size();i++){
    if(i>ind&&candidates[i]==candidates[i-1])continue;
    if(candidates[i]>target)break;
    ds.push_back(candidates[i]);
    solve(candidates,target-candidates[i],ans,ds,i+1);
    ds.pop_back();
}
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        solve(candidates,target,ans,ds,0);
        return ans;
        
    
}
};