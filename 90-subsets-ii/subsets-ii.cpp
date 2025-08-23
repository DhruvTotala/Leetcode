class Solution {
public:
    void recur(int idx, vector<int>& nums, vector<int>& temp, set<vector<int>>& st) {
        if(idx == nums.size()) {
            st.insert(temp);  // directly insert
            return;
        }

        // not take
        recur(idx + 1, nums, temp, st);

        // take
        temp.push_back(nums[idx]);
        recur(idx + 1, nums, temp, st);
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important for duplicates
        set<vector<int>> st;
        vector<int> temp;
        recur(0, nums, temp, st);

        // convert set to vector
        return vector<vector<int>>(st.begin(), st.end());
    }
};
