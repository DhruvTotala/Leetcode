class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Store obstacles for quick lookup
        set<pair<int,int>> blocked;
        for (auto &o : obstacles) {
            blocked.insert({o[0], o[1]});
        }

        // Directions: North, East, South, West
        vector<pair<int,int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int x = 0, y = 0;
        int dir = 0; // start facing North
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                // turn right
                dir = (dir + 1) % 4;
            } 
            else if (cmd == -2) {
                // turn left
                dir = (dir + 3) % 4;
            } 
            else {
                // move forward step by step
                while (cmd--) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;

                    // stop if obstacle is ahead
                    if (blocked.count({nx, ny})) break;

                    x = nx;
                    y = ny;

                    maxDist = max(maxDist, x * x + y * y);
                }
            }
        }

        return maxDist;
    }
};