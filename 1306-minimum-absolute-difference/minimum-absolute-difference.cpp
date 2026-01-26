class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int min_diff = INT_MAX;
        vector<vector<int>> res;
        for(int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            if(diff < min_diff) {
                min_diff = diff;
                res.clear();
                res.push_back({arr[i - 1], arr[i]});
            } else if(diff == min_diff) {
                res.push_back({arr[i - 1], arr[i]});
            }
        }
        return res;
    }
};