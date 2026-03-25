class Solution {
public:
    pair <int, int> bfs(unordered_map <int, vector<int>>& adj, int node) {
        queue <int> q;
        q.push(node);
        unordered_map <int, bool> visited;
        visited[node] = true;
        int dist = 0;
        int farthestNode = node;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int curr = q.front();
                q.pop();
                farthestNode = curr;
                for(auto &neigh : adj[curr]) {
                    if(!visited[neigh]) {
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
            if(!q.empty()) dist++;
        }
        return {farthestNode, dist};
    }
    int findDiameter(unordered_map <int, vector<int>>& adj) {
        //1. find the farthest node from a random node - 0
        auto [farthestNode, dist] = bfs(adj, 0);
        //2. farthest node is nothing but one end of the diameter

        //3. find farthest node from above end, we will eventually get the other end of the node
        auto [otherEndNode, diameter] = bfs(adj, farthestNode);
        return diameter;
    }
    unordered_map <int, vector<int>> buildadj(vector<vector<int>>& edges) {
        unordered_map <int, vector<int>> mp;
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        return mp;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map <int, vector<int>> adj1 = buildadj(edges1);
        unordered_map <int, vector<int>> adj2 = buildadj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);
        int all = (d1 + 1) / 2 + (d2 + 1) / 2 + 1;
        return max({d1, d2, all});
    }
};