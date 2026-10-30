class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            g[u].push_back({v, w});
        }
        
        vector<vector<long long>> dist(n, vector<long long>(k + 1, 1e18));
        priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
        
        int initial_streak = 1;
        dist[0][initial_streak] = 0;
        pq.push({0, 0, initial_streak});
        
        while (!pq.empty()) {
            auto [d, u, cur] = pq.top();
            pq.pop();
            
            if (u == n - 1) {
                return d;
            }
            
            if (d > dist[u][cur]) {
                continue;
            }
            
            for (const auto& edge : g[u]) {
                int v = edge.first;
                int w = edge.second;
                
                int nxt = (labels[v] == labels[u]) ? cur + 1 : 1;
                
                if (nxt <= k) {
                    long long nd = d + w;
                    if (nd < dist[v][nxt]) {
                        dist[v][nxt] = nd;
                        pq.push({nd, v, nxt});
                    }
                }
            }
        }
        
        return -1;
    }
};