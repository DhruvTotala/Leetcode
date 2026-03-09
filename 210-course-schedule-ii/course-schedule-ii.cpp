class Solution {
public:
    bool iscycledfs;
    void dfs(unordered_map <int, vector<int>>& mp, int node, vector <bool>& visited, 
    vector <bool>& inrecursion, stack <int>& st) {
        visited[node] = true;
        inrecursion[node] = true;
        for(auto &it : mp[node]) {
            if(inrecursion[it] == true) {
                iscycledfs = true;
                return;
            }
            if(!visited[it]) dfs(mp, it, visited, inrecursion, st);
        }
        st.push(node);
        inrecursion[node] = false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map <int, vector<int>> mp;
        vector <bool> visited(numCourses, false);
        vector <bool> inrecursion(numCourses, false);
        iscycledfs = false;
        for(vector <int>& v : prerequisites) {
            int a = v[0];
            int b = v[1];
            mp[b].push_back(a);
        }
        stack <int> st;
        for(int i = 0; i < numCourses; i++) {
            if(!visited[i]) dfs(mp, i, visited, inrecursion, st);
        }
        vector <int> ans;
        if(iscycledfs) return {};
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};