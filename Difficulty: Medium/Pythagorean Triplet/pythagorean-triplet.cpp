class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        if(arr.size()<3)
         return false;
         vector<int>sqr;
         for(int i:arr)
         sqr.push_back(i*i);
         sort(sqr.begin(),sqr.end());
         unordered_set<int>st;
         for(int i:sqr)
         st.insert(i);
         for(int i=2;i<sqr.size();i++)
         {
             int l=0;
             int r=i-1;
             while(l<r)
             {
                int sum = sqr[l] + sqr[r];
                if (sum == sqr[i]) {
                    return true;
                } else if (sum < sqr[i]) {
                    ++l;
                } else {
                    --r;
                }
             }
         }
         
         return false;
         
    }
};

