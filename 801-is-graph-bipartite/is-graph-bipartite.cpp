class Solution {
public:
    bool isvalid(int node, int curr, vector<vector<int>>& graph, vector <int>& color, vector <int>& visited) {
        visited[node] = true;
        color[node] = curr;
        for(int n : graph[node]) {
            if(!visited[n]) {
                if(isvalid(n, !curr, graph, color, visited)) return true;
            }
            else if(color[n] == color[node]) return true;
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> visited(n, false);
        vector <int> color(n);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                if (isvalid(i, 0, graph, color, visited)) return false;
            }
        }
        return true;
    }
};