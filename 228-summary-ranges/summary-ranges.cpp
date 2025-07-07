class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        int i = 0;

        while (i < n) {
            int start = nums[i];
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            int end = nums[i];
            if (start == end)
                result.push_back(to_string(start));
            else
                result.push_back(to_string(start) + "->" + to_string(end));
            i++;
        }

        return result;
    }
};
