class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
      int n=arr.size();
      int repeat=-1,miss=-1;
      vector<int> count(n,0);
      for(int i=0;i<n;i++){
          count[arr[i]-1]++;
      }
      for(int i=0;i<n;i++){
          if(count[i]==2){
              repeat=i+1;
              break;
          }
      }
          for(int i=0;i<n;i++){
          if(count[i]==0){
              miss=i+1;
              break;
          }
          }
      return {repeat,miss};
    }
};

