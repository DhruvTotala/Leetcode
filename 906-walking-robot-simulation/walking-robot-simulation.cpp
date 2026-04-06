class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set <string> st;
        for(vector <int>& v : obstacles) {
            string key = to_string(v[0]) + "-" + to_string(v[1]);
            st.insert(key);
        }
        int x = 0;
        int y = 0;
        int max_dist = 0;
        pair <int, int> dir = {0, 1};
        for(int i = 0; i < commands.size(); i++) {
            if(commands[i] == -2) dir = {-dir.second, dir.first};
            else if(commands[i] == -1) dir = {dir.second, -dir.first};
            else {
                for(int step = 0; step < commands[i]; step++) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;
                    string nkey = to_string(nx) + "-" + to_string(ny);
                    if(st.find(nkey) != st.end()) break;
                    x = nx;
                    y = ny;
                    max_dist = max(max_dist, x * x + y * y);
                }
            } 
        }
        return max_dist;
    }
};