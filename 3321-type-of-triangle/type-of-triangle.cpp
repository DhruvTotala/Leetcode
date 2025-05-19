class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums[0] + nums[1] <= nums[2]) return "none";
        unordered_set <int> s(nums.begin(), nums.end());
        if(s.size() == 1) return "equilateral";
        else if(s.size() == 2) return "isosceles";
        else return "scalene";
        }
};