class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1, mid = 0;

        // First pass: count smaller elements
        for (int num : nums)
            if (num < pivot) result[left++] = num;

        // Second pass: place pivot elements
        mid = left;
        for (int num : nums)
            if (num == pivot) result[mid++] = num;

        // Third pass: place greater elements
        for (int num : nums)
            if (num > pivot) result[mid++] = num;

        return result;
    }
};
