class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int start = 0;
        int n = gain.size();
        for(int i = 0; i < n; i++) {
            int net_gain = start + gain[i];
            start = net_gain;
            ans = max(ans, net_gain);
        }
        return ans;
    }
};