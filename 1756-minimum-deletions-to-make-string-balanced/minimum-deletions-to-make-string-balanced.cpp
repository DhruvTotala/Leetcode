class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int count = 0;
        int b_count = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'b') b_count++;
            else count = min(count + 1, b_count);
        }
        return count;
    }
};