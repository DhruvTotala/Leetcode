class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> p;  // To check presence of elements
        for (int num : nums) p[num] = true;  // Store all numbers

        int count = 0;

        for (int num : nums) {
            // Start a new sequence if `num - 1` does not exist
            if (!p[num - 1]) {
                int ans = 0;
                int s = num;

                while (p[s]) {  // Expand sequence
                    ans++;
                    p[s] = false;  // Mark as visited
                    s++;
                }

                count = max(count, ans);
            }
        }

        return count;
    }
};
