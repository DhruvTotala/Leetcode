class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";
        for (int i = 0; i < n; ++i) {
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        return result;
    }
};