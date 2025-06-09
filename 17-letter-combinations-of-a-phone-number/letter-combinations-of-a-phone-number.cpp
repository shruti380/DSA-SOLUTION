class Solution {
public:
void solve(string digits,vector<string>&ans,string &output,int ind,vector<string>&mapping){
    if(ind>=digits.size()){
        ans.push_back(output);
        return ;
    }
    int number=digits[ind]-'0';
    string val=mapping[number];
    for(int i=0;i<val.size();i++){
        output.push_back(val[i]);
        solve(digits,ans,output,ind+1,mapping);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {

        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
        string output;
        vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,ans,output,0,mapping);
        return ans;
        
    }
};