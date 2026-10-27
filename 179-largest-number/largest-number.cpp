
class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto mycomp = [](string &s1, string &s2) {
            return s1 + s2 > s2 + s1;
        };

        int n = nums.size();
        vector<string> res;

        for (int i = 0; i < n; i++) {
            res.push_back(to_string(nums[i]));
        }

        sort(res.begin(), res.end(), mycomp);

        if (res[0] == "0") return "0";

        string ans = "";

        for (string &s : res) {
            ans += s;
        }

        return ans;
    }
};
