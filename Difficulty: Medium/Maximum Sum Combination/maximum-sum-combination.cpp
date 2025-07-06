class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        vector<int>ans;
        int n=a.size();
        int m=b.size();
        set<pair<int,int>>st;
        priority_queue<pair<int,pair<int,int>>>pq;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        pq.push({a.back()+b.back(),{n-1,m-1}});
        while(k--&&!pq.empty()){
            
           auto it=pq.top();
           pq.pop();
           int sum=it.first;
           int i=it.second.first;
           int j=it.second.second;
           st.insert({i,j});
           ans.push_back(sum);
           
           if(i-1>=0&&st.find({i-1,j})==st.end()){
               pq.push({a[i-1]+b[j],{i-1,j}});
               st.insert({i-1,j});
           }
           if(j-1>=0&&st.find({i,j-1})==st.end()){
               pq.push({a[i]+b[j-1],{i,j-1}});
               st.insert({i,j-1});
           }
           
           
           
        }
        return ans;
        
        
        
    }
};