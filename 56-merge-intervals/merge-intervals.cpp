class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};

        // Sorting is O(n log n)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);

        // Merge step is O(n)
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= ans.back()[1]) {
                // Overlap: extend the last interval
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                // No overlap: add new interval
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
