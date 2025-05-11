class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            if (num & 1) {  // Bitwise check for odd
                count++;
                if (count == 3) return true;
            } else {
                count = 0;
            }
        }
        return false;
    }
};
