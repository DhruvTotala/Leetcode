class Solution {
public:

    long long getfromformula(long long count, long long x) {
        return (count * x) - ((count * (count + 1)) / 2);
    }

    int maxValue(int n, int index, int maxSum) {
        long long low = 1;
        long long  high = maxSum;
        int count = 0;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            long long left_part = min((long long)index, mid - 1);
            long long left_sum = getfromformula(left_part, mid);
            left_sum += max((long long)0, index - (mid - 1));
            
            long long right_part = min((long long) n - index - 1, mid - 1);
            long long right_sum = getfromformula(right_part, mid);
            right_sum += max((long long)0, n - index - 1 - mid + 1);

            long long total_sum = right_sum + mid + left_sum;
            if(total_sum <= maxSum) {
                count = max((long long)count, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return count;
    }
};