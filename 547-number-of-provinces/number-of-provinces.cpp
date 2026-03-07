class Solution {
public:
    void bfs(unordered_map<int, vector<int>>& mp, int node, vector <bool>& visited) {
        queue <int> q;
        q.push(node);
        visited[node] = true;
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            for(auto &it : mp[f]) {
                if(!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1){
                mp[i].push_back(j);
                mp[j].push_back(i);
                }
            }
        }
        vector <bool> visited(n, false);
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bfs(mp, i, visited);
                count++;
            }
        }
        return count;
    }
};