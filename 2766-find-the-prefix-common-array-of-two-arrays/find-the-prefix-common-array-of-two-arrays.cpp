class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector <int> ans(n);
        int count = 0;
        unordered_set <int> s;
        for(int i = 0; i < n; i++) {
            if(A[i] == B[i]) {
                if(s.count(A[i]) == 0) count++;
            } else {
                if(s.count(A[i])) count++;
                if(s.count(B[i])) count++;
            }
            s.insert(A[i]);
            s.insert(B[i]);
            ans[i] = count;
        }
        return ans;
    }
};