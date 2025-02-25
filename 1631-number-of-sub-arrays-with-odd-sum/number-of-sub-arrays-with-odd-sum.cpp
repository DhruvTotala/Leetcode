class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1;  // Even count starts at 1 for empty subarray
        int sum = 0, result = 0;

        for (int num : arr) {
            sum += num;
            if (sum % 2 == 0) {
                result = (result + oddCount) % MOD; // Even sum: add the number of odd prefix sums
                evenCount++;
            } else {
                result = (result + evenCount) % MOD; // Odd sum: add the number of even prefix sums
                oddCount++;
            }
        }

        return result;
    }
};
