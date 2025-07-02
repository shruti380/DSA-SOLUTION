// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src){
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        
        st.insert({0, src});
        dist[src] = 0;
        
        while(!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            // Direct access to neighbors (much faster)
            for(auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edw = neighbor.second;
                
                if(dis + edw < dist[adjNode]) {
                    if(dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edw;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
    