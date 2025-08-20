class Solution {
public:

    bool isvalid(vector <int>& piles, int mid, int h) {
        int hrs = 0;
        for(int i = 0; i < piles.size(); i++) {
            hrs += (piles[i] + mid - 1) / mid;
            if(hrs > h) return false;
        }
        if(hrs <= h) {
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isvalid(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};