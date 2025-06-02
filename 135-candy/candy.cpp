const int N=20000;
using int2=pair<int, int>;
const int2 None={-1, -1};
int2 adj[N]; // at most 2 adjacent nodes
int deg[N];
class Solution {
public:
    static int candy(vector<int>& ratings) {
        const int n=ratings.size();
        for(int i=0; i<n; i++){// reset
            adj[i]=None;
            deg[i]=0;
        }
        for (int i=1; i<n; i++){// build adjacency list
            if (ratings[i-1]<ratings[i]){
                adj[i-1].first=i;// edge (i-1, i)
                deg[i]++;
            }
            else if (ratings[i-1]>ratings[i]){
                adj[i].second=i-1; // edge (i, i-1)
                deg[i-1]++;
            }
        }
        queue<int2> q; // (i, candies-1)
        for (int i=0; i<n; i++){
            if (adj[i]!=None && deg[i]==0)
                q.emplace(i, 0);
        }
        int ans=n;//each child has at least 1
        while(!q.empty()){
            auto [i, c]=q.front(); q.pop();
            ans+=c;
            int j0=adj[i].first, j1=adj[i].second;// at most 2 adj nodes
            if (j0!=-1 && --deg[j0]==0)
                q.emplace(j0, c+1);
            if (j1!=-1 && --deg[j1]==0)
                q.emplace(j1, c+1);
        }
        return ans;
    }
};