class Solution {
public:
    bool iscycledfs(unordered_map <int, vector<int>>& adj, int node, vector <bool>& 
    visited, vector <bool>& inrecur) {
        visited[node] = true;
        inrecur[node] = true;
        for(auto &it : adj[node]) {
            if(!visited[it] && iscycledfs(adj, it, visited, inrecur)) return true;
            else if(inrecur[it] == true) return true;
        }
        inrecur[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int, vector<int>> adj;
        for(vector <int>& v : prerequisites) {
            int a = v[0];
            int b = v[1];
            adj[b].push_back(a);
        }
        vector <bool> visited(numCourses, false);
        vector <bool> inrecur(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i] && iscycledfs(adj, i, visited, inrecur)) return false;
        }
        return true;
    }
};