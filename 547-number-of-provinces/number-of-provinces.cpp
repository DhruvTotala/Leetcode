class Solution {
public:
    int n;
    void dfs(unordered_map <int, vector<int>>& mp, int node, vector <bool>& visited) {
        visited[node] = true;
        for(auto &it : mp[node]) {
            if(!visited[it]) dfs(mp, it, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map <int, vector <int>> mp;
        n = isConnected.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector <bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(mp, i, visited);
                count++;
            }
        }
        return count;    
    }
};