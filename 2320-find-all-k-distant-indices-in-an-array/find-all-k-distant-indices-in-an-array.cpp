class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector <int> result;
        vector <int> idx;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] == key) idx.push_back(i);
        }
        for(int i = 0; i < n; i++) {
            for(int j : idx) {
                    if(abs(i - j) <= k) {
                    result.push_back(i);
                    break;
                }
            }
        }
        return result;
    }
};