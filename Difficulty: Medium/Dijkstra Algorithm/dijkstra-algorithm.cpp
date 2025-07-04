// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>>adj(V);
        vector<int>dist(V,1e9);
        for(auto edge:edges){
            int u=edge[0],v=edge[1],w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
         dist[src] = 0;
        set<pair<int,int>>st;
        st.insert({0,src});
        while(!st.empty()){
        auto it=*(st.begin());
        int dis=it.first;
        int node=it.second;
        st.erase(it);
        
        for(auto neigh:adj[node]){
            int adjNode=neigh.first;
            int  edw=neigh.second;
            if(edw+dis<dist[adjNode]){
                if(dist[node]!=1e9){
                    st.erase({dist[adjNode],adjNode});
                }
                dist[adjNode]=edw+dis;;
                st.insert({dist[adjNode],adjNode});
            }
        }
        }
        return dist;
        
    }
};