class Solution {
public:
    long long power(long long b, long long e) {
        long long ans = 1;
        long long mod = 1000000007;
        b %= mod;
        while (e > 0) {
            if (e % 2 == 1)  ans = (ans * b) % mod;
            
            b = (b * b) % mod;
            e /= 2;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        vector<vector<int>> t = edges;

        int n_nodes = t.size() + 1;

        vector<vector<int>> adj(n_nodes + 1);
        for (const auto& edge : t) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<pair<int, int>> q;
        vector<int> node_depth(n_nodes + 1, -1);
        
        q.push({1, 0});
        node_depth[1] = 0;
        
        int max_path = 0;

        while (!q.empty()) {
            pair<int, int> current_item = q.front();
            q.pop();
            int u = current_item.first;
            int d = current_item.second;

            max_path = max(max_path, d);

            for (int v : adj[u]) {
                if (node_depth[v] == -1) {
                    node_depth[v] = d+ 1;
                    q.push({v, d + 1});
                }
            }
        }
        
        int fy = max_path;

        if (fy == 0) return 0; 
        

        long long num_ways = power(2, fy - 1);
        
        return static_cast<int>(num_ways);
    }
};