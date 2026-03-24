class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map <int, vector<int>> adj;
        unordered_map <int, int> indeg, outdeg;
        for(auto &it : pairs) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        int start_node = pairs[0][0];

        for(auto &v : adj) {
            int node = v.first;
            if(outdeg[node] - indeg[node] == 1) {
                start_node = node;
                break;
            }
        }
        vector <int> eulerpath;
        stack <int> st;
        st.push(start_node);
        while(!st.empty()) {
            int curr = st.top();
            if(!adj[curr].empty()) {
                int neigh = adj[curr].back();
                adj[curr].pop_back();
                st.push(neigh);
            } else {
                eulerpath.push_back(curr);
                st.pop();
            }
        }
        reverse(eulerpath.begin(), eulerpath.end());
        vector<vector<int>> ans;
        for(int i = 0; i < eulerpath.size() - 1; i++) {
            ans.push_back({eulerpath[i], eulerpath[i + 1]});
        }
        return ans;
    }
};