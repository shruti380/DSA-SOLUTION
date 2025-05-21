class Solution {
  public:
  int count(int mid,int m,int n){
      int countSum=0;
      for(int i=1;i<=m;i++){
         countSum+= min(mid/i,n);
          
      }
      return countSum;
  }
    
    int kthSmallest(int m, int n, int k){
        // Brute Forc1
        // vector<int>result;
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         int val=i*j;
        //         result.push_back(val);
        //     }
        // }
        // sort(result.begin(),result.end());
        // return result[k-1];
        
        // Better Approach
        // priority_queue<int>pq;
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         int val=i*j;
        //         if(pq.size()<k){
                    
        //             pq.push(val);
        //         }
        //             else if(pq.top()>val){
        //                 pq.pop();
        //                 pq.push(val);
        //             }
        //         }
        //     }
            
        
        // return pq.top();
        
        
        // Better Approach
        int l=1;
        int h=m*n;
        while(l<h){
            int mid=(l+h)/2;
            if(count(mid,m,n)>=k){
                h=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};