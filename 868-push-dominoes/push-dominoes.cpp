class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int>Ldominoes(n);
        vector<int>Rdominoes(n);
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                Rdominoes[i]=i;
            }
            else if(dominoes[i]=='.'){
                Rdominoes[i]=i>0?Rdominoes[i-1]:-1;
            }
            else{
                Rdominoes[i]=-1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                 Ldominoes[i]=i;
            }
            else if(dominoes[i]=='.'){
                Ldominoes[i]=i<n-1?Ldominoes[i+1]:-1;
            }
            else{
                Ldominoes[i]=-1;
            }
        }
        string ans(n,'.');
        for(int i=0;i<n;i++){
            if(dominoes[i] != '.') {
                ans[i] = dominoes[i];
            }
            else if(Rdominoes[i] == -1 && Ldominoes[i] == -1) {
                ans[i] = '.';
            }
            else if(Rdominoes[i] == -1) {
                ans[i] = 'L';
            }
            else if(Ldominoes[i] == -1) {
                ans[i] = 'R';
            }
            else {
                int distR = i - Rdominoes[i];
                int distL = Ldominoes[i] - i;
                if(distR < distL) {
                    ans[i] = 'R';
                }
                else if(distL < distR) {
                    ans[i] = 'L';
                }
                else {
                    ans[i] = '.';
                }
            }
        }
        return ans;
    }
};