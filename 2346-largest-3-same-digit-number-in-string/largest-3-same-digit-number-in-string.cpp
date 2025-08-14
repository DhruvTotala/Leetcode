class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        char max_char = ' ';
        for(int i = 2; i < n; i++) {
            if((num[i] == num[i - 1]) && (num[i] == num[i - 2])) {
                max_char = max(max_char, num[i]);
            }
        }
        if(max_char == ' ') {
            return "";
        }
        return string(3, max_char);
    }
};