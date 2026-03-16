class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> points(mx + 1, 0);

        for (int num : nums) {
            points[num] += num;
        }

        return rob(points);
    }

    int rob(vector<int>& arr) {
        int prev = 0;
        int curr = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int nxt = max(arr[i] + prev, curr);
            prev = curr;
            curr = nxt;
        }

        return curr;
    }
};