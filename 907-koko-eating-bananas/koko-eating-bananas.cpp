class Solution {
public:

    bool ispossible(vector <int>& piles, int mid, int h) {
        int total_time = 0;
        for(int i = 0; i < piles.size(); i++) {
            total_time += (piles[i] + mid - 1) / mid;
            if(total_time > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(ispossible(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};