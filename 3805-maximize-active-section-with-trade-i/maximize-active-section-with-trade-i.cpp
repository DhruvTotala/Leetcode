class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int a_count = count(s.begin(), s.end(), '1');
        vector <int> inactiveblocks;
        int i = 0;
        while(i < n) {
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;
                inactiveblocks.push_back(i - start);
            } else {
                i++;
            }
        }
        int max_ans = 0;
        for(int i = 1; i < inactiveblocks.size(); i++) {
            max_ans = max(max_ans, inactiveblocks[i] + inactiveblocks[i - 1]);
        }
        return max_ans + a_count;
    }
};