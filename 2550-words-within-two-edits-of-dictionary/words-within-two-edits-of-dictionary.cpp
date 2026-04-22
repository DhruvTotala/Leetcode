class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector <string> ans;
        for(auto &q : queries) {
            for(auto &s : dictionary) {
                int diff = 0; 
                for(int i = 0; i < q.size(); i++) {
                    if(s[i] != q[i]) diff++;
                }
                if(diff <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};