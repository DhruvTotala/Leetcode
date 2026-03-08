class Solution {
public:
    bool topology(unordered_map <int, vector<int>>& adj, vector <int>& indegree, int n) {
        int count = 0;
        queue <int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }

        while(!q.empty()) {
            int f = q.front();
            q.pop();
            for(auto it : adj[f]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    count++;
                    q.push(it);
                }
            }
        }
        if(count == n) return true;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int, vector<int>> adj;
        vector <int> indegree(numCourses, 0);
        for(vector <int>& v : prerequisites) {
            int a = v[0];
            int b = v[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        return topology(adj, indegree, numCourses);
    }
};