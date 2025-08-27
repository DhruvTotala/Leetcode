class Solution {
public:
    // sum of first cnt numbers decreasing from (x-1, x-2, ...)
    long long calc(long long cnt, long long x) {
        if (cnt >= x) {
            // full decreasing sequence until 1, then rest are 1's
            return (x - 1) * x / 2 + (cnt - (x - 1));
        } else {
            // just cnt terms of decreasing sequence
            return (x - 1 + x - cnt) * cnt / 2;
        }
    }

    int maxValue(int n, int index, int maxSum) {
        long long low = 1, high = maxSum, ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long left_sum = calc(index, mid);
            long long right_sum = calc(n - index - 1, mid);
            long long total = left_sum + right_sum + mid;

            if (total <= maxSum) {
                ans = mid;        // feasible, try higher
                low = mid + 1;
            } else {
                high = mid - 1;   // too large
            }
        }

        return ans;
    }
};
