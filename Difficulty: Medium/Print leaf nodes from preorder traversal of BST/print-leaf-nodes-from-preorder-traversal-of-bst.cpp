class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        stack<int>st;
        vector<int>ans;
        st.push(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            if(st.top()>preorder[i]){
                st.push(preorder[i]);
            }
            else{
                int count=0;
                int temp=st.top();
                while(!st.empty()&&st.top()<preorder[i]){
                    st.pop();
                    count++;
                    
                    
                }
                st.push(preorder[i]);
                if(count>=2)ans.push_back(temp);
            }
            
        }
        ans.push_back(st.top());
        return ans;
        
    }
};