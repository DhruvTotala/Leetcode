class Solution {
public:
    vector <int> topo(unordered_map <int, vector<int>>& mp, int n, vector <int>& indegree) {
        queue <int> q;
        vector <int> result;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                count++;
            }
        }
        while(!q.empty()) {
            int f = q.front();
            q.pop();
            result.push_back(f);
            for(auto &it : mp[f]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                    count++;
                }
            }
        }
        if(count == n) return result;
        return {};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int, vector<int>> mp;
        vector <int> indegree(numCourses, 0);
        for(vector <int>& v : prerequisites) {
            int a = v[0];
            int b = v[1];
            mp[b].push_back(a);
            indegree[a]++;
        }
        return topo(mp, numCourses, indegree);
    }
};