class Solution {
public:
int calculateWeight(vector<int>&weights,int capacity){
    int n=weights.size();
    int load=0;
    int day=1;
    for(int i=0;i<n;i++){
        if(load+weights[i]>capacity){
            day=day+1;
            load=weights[i];

        }
        else{
            load+=weights[i];
        }
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int days1=calculateWeight(weights,mid);
            if(days1<=days){
               ans=mid;
               
                 high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};