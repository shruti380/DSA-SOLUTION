class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int left=0;
        int right=0;
        int n=trainers.size();
        int m=players.size();
        int matches=0;
        while(left<m&&right<n){
            if(players[left]<=trainers[right]){
                left++;
                right++;
                matches++;

            }
            else if(players[left]>trainers[right]){
                right++;
            }
        }
        return matches;

        
    }
};