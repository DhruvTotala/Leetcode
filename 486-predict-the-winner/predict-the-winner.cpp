class Solution {
public:
    int solve(int i, int j, vector <int>& nums) {
        if(i > j) return 0;
        if(i == j) return nums[i];

        int take_i = nums[i] + min(solve(i + 2, j, nums), solve(i + 1, j - 1, nums));
        int take_j = nums[j] + min(solve(i + 1, j - 1, nums), solve(i, j - 2, nums));

        return max(take_i, take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int total_score = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        int first_score = solve(0, n - 1, nums);
        int second_score = total_score - first_score;

        return first_score >= second_score;
    }
};