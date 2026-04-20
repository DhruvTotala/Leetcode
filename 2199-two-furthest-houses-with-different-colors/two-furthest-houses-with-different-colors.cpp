class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = 0;
        int ans = 0;
        while(colors[i] == colors[n - 1]) i++;
        ans = max(ans, abs(i - (n - 1)));
        i = n - 1;
        while(colors[0] == colors[i]) i--;
        ans = max(ans, i);
        return ans;
    }
};