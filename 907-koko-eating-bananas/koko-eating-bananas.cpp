class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
       int result=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long ans=0;
            for(int i=0;i<piles.size();i++){
            ans+=ceil(double(piles[i])/double(mid));
            }
            if(ans<=h){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        
        return result;;
                
    }
};