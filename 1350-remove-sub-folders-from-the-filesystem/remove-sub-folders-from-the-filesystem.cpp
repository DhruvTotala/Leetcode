class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end()); // Sort folders lexicographically
        vector<string> res;
        string prev = "";
        for (auto& f : folder) {
            // If prev is empty or f is not a subfolder of prev, add it
            if (prev.empty() || f.substr(0, prev.size()) != prev || f[prev.size()] != '/') {
                res.push_back(f);
                prev = f;
            }
        }
        return res;
    }
};
