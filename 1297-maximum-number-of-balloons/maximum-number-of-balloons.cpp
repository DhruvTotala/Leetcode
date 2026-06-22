class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector <int> count(26, 0);
        for(char ch : text) {
            count[ch - 'a']++;
        }
        return min({count['a' - 'a'], count['b' - 'a'], count['l' - 'a'] / 2, 
        count['o' - 'a'] / 2, count['n' - 'a']});
    }
};