class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int, int>> indexed;
        for (int i = 0; i < nums.size(); ++i) indexed.push_back({nums[i], i});
        sort(indexed.begin(), indexed.end());

        vector<vector<int>> groups = {{indexed[0].second}};
        for (int i = 1; i < nums.size(); ++i) {
            if (indexed[i].first - indexed[i - 1].first <= limit)
                groups.back().push_back(indexed[i].second);
            else
                groups.push_back({indexed[i].second});
        }

        for (auto& group : groups) {
            vector<int> sortedVals;
            for (int i : group) sortedVals.push_back(nums[i]);
            sort(sortedVals.begin(), sortedVals.end());
            sort(group.begin(), group.end());
            for (int i = 0; i < group.size(); ++i) nums[group[i]] = sortedVals[i];
        }
        return nums;
    }
};
