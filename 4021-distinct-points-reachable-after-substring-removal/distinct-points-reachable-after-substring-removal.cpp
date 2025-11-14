class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();

        vector<int> xpos(n), ypos(n);

        // Build prefix coordinates
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                xpos[i] = xpos[i - 1];
                ypos[i] = ypos[i - 1];
            }

            if (s[i] == 'U') ypos[i]++;
            else if (s[i] == 'D') ypos[i]--;
            else if (s[i] == 'R') xpos[i]++;
            else xpos[i]--; // 'L'
        }

        set<pair<int,int>> st;

        for (int i = k - 1; i < n; i++) {
            int xshift, yshift;

            if (i == k - 1) { 
                xshift = xpos[i];
                yshift = ypos[i];
            } else {
                xshift = xpos[i] - xpos[i - k];
                yshift = ypos[i] - ypos[i - k];
            }

            // Final shifted point
            st.insert({xpos[n - 1] - xshift, ypos[n - 1] - yshift});
        }

        return st.size();
    }
};
