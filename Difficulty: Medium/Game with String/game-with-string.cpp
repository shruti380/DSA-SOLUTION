class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<int,int>mpp;
        for(auto i:s){
            mpp[i]++;
        }
        vector<int>arr;
        for(auto i:mpp)arr.push_back(i.second);
        while(k--){
            sort(arr.begin(),arr.end());
            arr[arr.size()-1]--;
        }
        int sum=0;
        for(auto i:arr){
            sum+=i*i;
        }
        return sum;
    }
};