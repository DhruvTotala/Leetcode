class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector <int> result;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(nums[j] == key && abs(i - j) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};