// User function Template for C++

class Solution {
  public:
  void recursion(int num,vector<string>&ans,string&s){
      if(s.size()>=2)
          if(s[s.size()-1]==s[s.size()-2]&&s[s.size()-1]=='1')return ;
          if(s.size()==num){
              ans.push_back(s);
              return;
          }
          s+="0";
          recursion(num,ans,s);
          s=s.substr(0,s.size()-1);
          s+="1";
          recursion(num,ans,s);
          s=s.substr(0,s.size()-1);
      }
      
  
    vector<string> generateBinaryStrings(int num) {
        string s;
        vector<string>ans;
        recursion(num,ans,s);
        return ans;
        
    }
};