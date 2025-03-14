class Solution {
public:
    bool canDistribute(const vector<int>& candies, int mid, long long k) {
        for(int candy : candies) {
            k -= candy / mid;
            if(k <= 0) return true;  // Early return optimization
        }
        return false;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long total = 0;
        int maxc = 0;
        for(int candy : candies) {
            total += candy;
            maxc = max(maxc, candy);
        }
        if(total < k) return 0;  // Not enough candies

        int l = 1, r = maxc, result = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(canDistribute(candies, mid, k)) {
                result = mid;
                l = mid + 1;  // Try larger mid
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};
