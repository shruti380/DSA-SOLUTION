class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>nse(n,0);
        vector<int>pse(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else{
                nse[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
                pse[i]=st.top();
            }
            st.push(i);
        }
        
        int maxArea=0;
        for(int i=0;i<n;i++){
            int width=nse[i]-pse[i]-1;
            int area=heights[i]*width;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
};