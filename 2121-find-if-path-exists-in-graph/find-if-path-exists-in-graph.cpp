class Solution {
public:
    bool isvalid(int source, int destination, vector<vector<int>>& adj, vector <int>& visited) {
        if(source == destination) return true;
        visited[source] = 1;
        for(int neighbour : adj[source]) {
            if(!visited[neighbour]) {
            if (isvalid(neighbour, destination, adj, visited) == true) return true;
        }
    }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector <int> visited(n, 0);
        return isvalid(source, destination, adj, visited);
    }
};