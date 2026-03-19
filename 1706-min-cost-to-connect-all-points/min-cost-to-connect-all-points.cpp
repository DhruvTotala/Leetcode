class Solution {
public:
    typedef pair<int, int> p;
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        unordered_map <int, vector<p>> mp;
        for(int i = 0; i < V; i++) {
            for(int j = i + 1; j < V; j++) {
                int wt = abs(points[i][0] - points[j][0]) + 
                         abs(points[i][1] - points[j][1]);
                mp[i].push_back({j, wt});
                mp[j].push_back({i, wt});
            }
        }
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});
        vector<bool>inmst(V, false);
        int sum = 0;
        while(!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            int wt = f.first;
            int node = f.second;
            if(inmst[node]) continue;
            inmst[node] = true;
            sum += wt;
            for(auto &it : mp[node]) {
                int neigh = it.first;
                int neigh_wt = it.second;
                if(inmst[neigh] == false) {
                    pq.push({neigh_wt, neigh});
                }
            }
        }
        return sum;
    }
};