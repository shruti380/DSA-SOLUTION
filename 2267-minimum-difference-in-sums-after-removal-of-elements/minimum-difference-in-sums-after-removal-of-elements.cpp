class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;

        vector<long long >left(3*n);
        vector<long long >right(3*n);

        priority_queue<int> maxHeap;

        long long sum=0;
        for(int i=0;i<3*n;i++){
           maxHeap.push(nums[i]);
           sum+=nums[i];
        
        if(maxHeap.size()>n){
            sum-=maxHeap.top();
            maxHeap.pop();
        }
        if(maxHeap.size()==n){
            left[i]=sum;
        }
        }
         sum=0;
        priority_queue<int,vector<int>,greater<int>>minheap;
        for(int i=3*n-1;i>=0;i--){
          
            minheap.push(nums[i]);
            sum+=nums[i];

            if(minheap.size()>n){
                sum-=minheap.top();
                minheap.pop();
            }
            if(minheap.size()==n){
                right[i]=sum;
            }
        }
        long long minDiff = LLONG_MAX;
        
        // The split point: first n elements come from left side, next n from right side
        // We need at least n elements on each side
        for (int i = n - 1; i < 2 * n; i++) {
            minDiff = min(minDiff, left[i] - right[i + 1]);
        }
        
        return minDiff;
    }
};

    
