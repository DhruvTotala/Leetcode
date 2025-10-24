#include <string> // Although not strictly needed, good to be aware of
#include <vector> // Although not strictly needed, good to be aware of

class Solution {
private:
    /**
     * @brief Helper function to check if a number is numerically balanced.
     * * An integer 'num' is numerically balanced if for every digit 'd'
     * in the number, 'd' occurs exactly 'd' times.
     * * @param num The integer to check.
     * @return true if the number is numerically balanced, false otherwise.
     */
    bool isBalanced(int num) {
        // Use a fixed-size array to store the counts of digits 0-9.
        int counts[10] = {0};
        
        // Use a temporary variable to extract digits without modifying 'num'.
        int temp = num;
        
        // Extract each digit from the number and update its count.
        while (temp > 0) {
            int digit = temp % 10;
            counts[digit]++;
            temp /= 10;
        }
        
        // Now, check if the balance condition is met for every digit.
        for (int d = 0; d < 10; ++d) {
            // If a digit 'd' is present (its count is > 0),
            // then its count must be equal to its value 'd'.
            if (counts[d] > 0 && counts[d] != d) {
                // If counts[d] is 3 but d is 2 (e.g., "222"), it's not balanced.
                // If d is 0 and counts[0] > 0 (e.g., "10"),
                // the check becomes (counts[0] != 0), which is true,
                // so it correctly returns false.
                return false;
            }
        }
        
        // If all present digits satisfy the condition, the number is balanced.
        return true;
    }

public:
    /**
     * @brief Finds the smallest numerically balanced number strictly greater than n.
     * * @param n The integer to start searching from.
     * @return The smallest numerically balanced integer > n.
     */
    int nextBeautifulNumber(int n) {
        // Start checking from the number immediately after n.
        int num = n + 1;
        
        // Keep incrementing and checking indefinitely.
        while (true) {
            // If we find a balanced number, return it immediately.
            if (isBalanced(num)) {
                return num;
            }
            // Otherwise, move to the next number.
            num++;
        }
        
        // The loop will always find an answer, so this is unreachable.
        // (Given n <= 10^6, the number 1,224,444 is a guaranteed
        // upper bound, ensuring the loop terminates).
        return -1; 
    }
};