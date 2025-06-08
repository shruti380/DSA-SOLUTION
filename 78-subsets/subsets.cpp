class Solution {
public:
void solve(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&output){
    if(ind>=nums.size()){
        ans.push_back(output);
        return;
    }
    //  exclude
    solve(ind+1,nums,ans,output);
    int el=nums[ind];
    output.push_back(el);
    solve(ind+1,nums,ans,output);
    output.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        int index=0;
        solve(index,nums,ans,output);
        return ans;

        
    }
};