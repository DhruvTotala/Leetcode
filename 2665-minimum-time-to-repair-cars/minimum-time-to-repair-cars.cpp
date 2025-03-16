#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool ispossible(vector<int>& ranks, long long mid, int cars) {
        long long carsfixed = 0;
        for (int rank : ranks) {
            carsfixed += (long long) sqrt(mid / rank);  // Efficient calculation
            if (carsfixed >= cars) return true;  // Early stopping condition
        }
        return carsfixed >= cars;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = (long long) (*min_element(ranks.begin(), ranks.end())) * cars * cars;
        long long result = -1;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (ispossible(ranks, mid, cars)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};
