class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> position(n, 0), reindex(n, 0);
        for (int i = 0; i < n; i++) {
            position[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            reindex[i] = position[nums1[i]]; 
        }
        vector<int> fen_small(n + 1, 0), fen_big(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            update(i, 1, fen_big);
        }
        long long result = 0;
        for (int i = 0; i < n; i++) {
            update(reindex[i] + 1, -1, fen_big);
            update(reindex[i] + 1, +1, fen_small);

            int smaller = query(reindex[i], fen_small);
            int bigger = query(n, fen_big) - query(reindex[i], fen_big);
            
            result += (long long)smaller * bigger;
        }
        return result;
    }
    void update(int index, int val, vector<int>& fen) {
        int n = fen.size();
        while (index < n) {
            fen[index] += val;
            index += (index & -index);
        }
    }
    int query(int index, vector<int>& fen) {
        int res = 0;
        while (index > 0) {
            res += fen[index];
            index -= (index & -index);
        }
        return res;
    }
};