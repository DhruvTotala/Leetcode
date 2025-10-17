class Solution {
public:

    void dfs(int node, vector <vector<int>>& isConnected, vector <int>& visited) {
        visited[node] = 1;
        for(int i = 0; i < isConnected.size(); i++) {
            if(isConnected[node][i] == 1 && visited[i] == 0) {
                dfs(i, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector <int> visited(n);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                count++;
                dfs(i, isConnected, visited);
            }
        }
        return count;
    }
};