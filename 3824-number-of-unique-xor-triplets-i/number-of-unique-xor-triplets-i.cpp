class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return n;
        int m = 0;
        while ((1 << m) < n + 1) m++;
        return 1 << m;
    }
};