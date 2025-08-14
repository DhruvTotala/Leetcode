class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            // Check if three consecutive characters are same
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string triple = num.substr(i, 3);
                if (ans == "" || triple > ans) {
                    ans = triple; // Lexicographic works because all triples have same digit
                }
            }
        }
        return ans;
    }
};
