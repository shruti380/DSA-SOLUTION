class Solution {
public:
    int minOperations(int n) {
        if(n==0)return 0;
        if(n==1)return 1; //subtract 2^0
        int x=1;
        while(x*2<n)x*=2; //find prev closest power of 2
        int prevdiff=n-x; //diff b/w number and prev closest power
        int nextdiff=2*x-n; //diff b/w number and next closest power
        int num1=minOperations(prevdiff); //operations to reach the diff
        int num2=minOperations(nextdiff);
        return (min(num1,num2))+1; //min operations to reach diff+ 1 operation to reach the power
    }
};