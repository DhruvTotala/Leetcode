class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        for (int x : nums) totalXor ^= x;

        // Case 1: all numbers are zero
        bool allZero = true;
        for (int x : nums) {
            if (x != 0) { allZero = false; break; }
        }
        if (allZero) return 0;

        // Case 2: total xor != 0 => whole array works
        if (totalXor != 0) return n;

        // Case 3: total xor == 0 but not all zero => drop one element
        return n - 1;
    }
};
