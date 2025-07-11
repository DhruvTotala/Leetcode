class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<>> free;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        for (int i = 0; i < n; ++i) free.push(i);

        for (auto& meet : meetings) {
            long long start = meet[0], end = meet[1];

            while (!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }

            if (!free.empty()) {
                int room = free.top(); free.pop();
                busy.emplace(end, room);
                count[room]++;
            } else {
                auto [availTime, room] = busy.top(); busy.pop();
                busy.emplace(availTime + (end - start), room);
                count[room]++;
            }
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};