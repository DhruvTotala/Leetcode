class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();

        vector <int> arr;
        for(int i = 0; i < m; i++) {
            for(int val : grid[i]) {
                arr.push_back(val);
            }
        }
        int first_rem = arr[0] % x;
        for(int val : arr) {
            if(val % x != first_rem) return -1;
        }

        sort(arr.begin(), arr.end());
        int median = arr[arr.size() / 2];
        int count = 0;
        for(int val : arr) {
            count += abs(val - median) / x;
        }
        return count;
    }
};