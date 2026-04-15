class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
            int startdist = abs(i - startIndex);
            int circular_dist = n - startdist;
            ans = min({ans, startdist, circular_dist});
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};