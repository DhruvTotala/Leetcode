class Solution {
public:
    #define ll long long
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        vector <int> ans(n);
        for(int i = 0; i < n; i++) {
            ll s = spells[i];
            ll low = 0;
            ll high = potions.size() - 1;
            int idx = -1;
            while(low <= high) {
                int mid = (low + high) / 2;
                if(potions[mid] * s >= success) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans[i] = (idx == -1) ? 0 : (potions.size() - idx);
        }
        return ans;
    }
};