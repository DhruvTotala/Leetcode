class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map <int, vector<pair<int, int>>> mp;
        for(auto &t : times) {
            int u = t[0];
            int v = t[1];
            int wt = t[2];
            mp[u].push_back({v, wt});
        }
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater <pair<int, int>>> pq;
        vector <int> result(n + 1, INT_MAX);
        result[k] = 0;
        pq.push({0, k});
        while(!pq.empty()) {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &vec : mp[node]) {
                int adj_node = vec.first;
                int wt = vec.second;
                if(dist + wt < result[adj_node]) {
                    result[adj_node] = dist + wt;
                    pq.push({dist + wt, adj_node});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i <= n; i++) {
            ans = max(ans, result[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};