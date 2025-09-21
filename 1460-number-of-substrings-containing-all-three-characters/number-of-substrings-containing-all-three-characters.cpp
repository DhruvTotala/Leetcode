class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector <int> mpp(3, -1);
        int count = 0;
        for(int i = 0; i < n; i++) {
            mpp[s[i] - 'a'] = i;
            if(mpp[0] != -1 && mpp[1] != -1 && mpp[2] != -1) {
                count += 1 + min({mpp[0], mpp[1], mpp[2]});
            }
        }
        return count;
    }
};