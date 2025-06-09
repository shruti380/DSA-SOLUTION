class Solution {
public:
void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&ds,int ind,int n){
   ans.push_back(ds);
   for(int i=ind;i<nums.size();i++){
    if(i!=ind&&nums[i]==nums[i-1])continue;
    ds.push_back(nums[i]);
    solve(nums,ans,ds,i+1,n);
    ds.pop_back();
    
   }

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ds;
        vector<vector<int>>ans;
        int n=nums.size();
        solve(nums,ans,ds,0,n);
        return ans;

        
    }
};