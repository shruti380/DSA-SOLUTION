class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        int  n=arr.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        stack<int>st;
        vector<int>ans(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&mpp[arr[st.top()]]<=mpp[arr[i]]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=arr[st.top()];
            }
            st.push(i);
        }
        return ans;
        
    }
};
