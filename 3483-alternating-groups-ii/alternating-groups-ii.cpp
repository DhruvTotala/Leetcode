class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int count = 0;
        int n = colors.size();
        int N = n + (k - 1);
        for(int i = 0; i < k - 1; i++) {
            colors.push_back(colors[i]);
        }
        int i = 0;
        int j = 1;
        while(j < N) {
            if(colors[j] == colors[j - 1]) {
                i = j;
                j++;
                continue;
            }
            if(j - i + 1 == k) {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};