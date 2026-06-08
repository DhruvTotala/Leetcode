class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int mid = 0;
        int left = 0;
        vector <int> result(n);

        for(int num : nums) {
            if(num < pivot) result[left++] = num;
        }
        mid = left;

        for(int num : nums) {
            if(num == pivot) result[mid++] = num;
        }

        for(int num : nums) {
            if(num > pivot) result[mid++] = num;
        }

        return result;
    }
};