class Solution {
public:
    bool caneat(vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for (int pile : piles) {
            hours += ceil((double)pile / speed); // use ceil function
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (caneat(piles, h, mid)) {
                high = mid - 1; // try smaller speed
            } else {
                low = mid + 1; // need faster speed
            }
        }
        return low;
    }
};
