class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();

        k %= n;

        for(int i = 0; i < m; i++) {
            vector<int> temp = mat[i];

            if(i % 2 == 0) {
                // left rotate using begin()
                rotate(temp.begin(), temp.begin() + k, temp.end());
            } 
            else {
                // right rotate using rbegin()
                rotate(temp.rbegin(), temp.rbegin() + k, temp.rend());
            }

            if(temp != mat[i]) return false;
        }

        return true;
    }
};