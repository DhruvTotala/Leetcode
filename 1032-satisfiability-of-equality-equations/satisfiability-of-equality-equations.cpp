class Solution {
public:
    vector <int> parent;
    vector <int> rank;
    
    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y) {
        int x_p = find(x);
        int y_p = find(y);
        
        if(rank[x_p] > rank[y_p]) parent[y_p] = x_p;
        else if(rank[x_p] < rank[y_p]) parent[x_p] = y_p;
        else {
            parent[x_p] = y_p;
            rank[y_p] += 1;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);
        
        for(int i = 0; i < 26; i++) parent[i] = i;
        for(string &s : equations) {
            if(s[1] == '=') Union(s[0] - 'a', s[3] - 'a');
        }
        for(string &s : equations) {
            if(s[1] == '!') {
                char f1 = s[0];
                char f2 = s[3];
                int first_one = find(f1 - 'a');
                int second_one = find(f2 - 'a');
                if(first_one == second_one) return false;
            }
        }
        return true;
    }
};