class Solution {
public:
bool possible(vector<int>& bloomDay,int day,int m,int k){
    int n=bloomDay.size();
    int cnt=0;
    int noOfB=0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
            noOfB+=(cnt/k);
            cnt=0;
        }
    }
    noOfB+=(cnt/k);
    return noOfB>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val=m*1ll*k*1ll;
        if(val>n)return -1;
        int mini=1e9;
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            mini=min(mini,bloomDay[i]);
            maxi=max(maxi,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};