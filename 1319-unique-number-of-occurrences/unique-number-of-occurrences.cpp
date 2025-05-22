class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int offset = 1000;
        vector <int> freq(2001, 0);
        vector <int> visited_freq(1001, 0);

        for(int num : arr) freq[num + offset]++;
        for(int i = 0; i <= 2000; i++) {
            if(freq[i] > 0) {
                if(visited_freq[freq[i]] == 1) return false;
                visited_freq[freq[i]] = 1;
            }
        }
        return true;
    }
};