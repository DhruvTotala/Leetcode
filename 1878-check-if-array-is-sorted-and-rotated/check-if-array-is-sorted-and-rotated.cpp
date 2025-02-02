class Solution {
public:
    bool check(vector<int>& nums) {
        int countDrops = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) { // Checking circularly
                countDrops++;
            }
            if (countDrops > 1) return false; // More than one drop means it's not a rotated sorted array
        }
        
        return true;
    }
};
