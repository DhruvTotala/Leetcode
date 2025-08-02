class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> mp;
        int n = basket1.size();
        int g = INT_MAX;

        for (int i = 0; i < n; i++) {
            mp[basket1[i]]++;
            mp[basket2[i]]--;
            g = min({g, basket1[i], basket2[i]});
        }

        vector<int> extra1, extra2;

        for (auto &[num, freq] : mp) {
            if (freq % 2 != 0) return -1;
            int f = abs(freq) / 2;
            if (freq > 0) while (f--) extra1.push_back(num);
            else while (f--) extra2.push_back(num);
        }

        if (extra1.size() != extra2.size()) return -1;

        sort(extra1.begin(), extra1.end());
        sort(extra2.begin(), extra2.end(), greater<int>()); // to pair smallest with largest

        long long cost = 0;
        int m = extra1.size();
        for (int i = 0; i < m; i++) {
            cost += min(1LL * g * 2, 1LL * min(extra1[i], extra2[i]));
        }

        return cost;
    }
};
