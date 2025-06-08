long long mod=1e9+7;
class Solution {
public:
long long pos(long long x,long long n){
    x=x%mod;
    int ans=1;
    while(n>0){
        if(n%2==1){
            ans=(ans*x)%mod;
            n=n-1;

        }
        else{
            x=(x*x)%mod;
            n=n/2;
        }
    }
    return ans;

}
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=(n)/2;
        long long  final=(pos(5,even)*pos(4,odd))%mod;
        return final;
        
        
    }
};