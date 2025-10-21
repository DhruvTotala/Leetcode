class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int maxele = *max_element(nums.begin(), nums.end());

        vector <int> freq(maxele + 1, 0);
        for(auto it : nums) {
            freq[it]++;
        }
        for(int i = 1; i <= maxele; i++) {
            freq[i] += freq[i - 1];
        }
        int result = 0;
        for(int i = 0; i <= maxele; i++) {
            if(freq[i] == 0) continue;

            int leftnum = max(0, i - k);
            int rightnum = min(maxele, i + k);
            int totalcount = freq[rightnum] - (leftnum > 0 ? freq[leftnum - 1] : 0);
            int targetcount = freq[i] - (i > 0 ? freq[i - 1] : 0);
            int need_conversion = totalcount - targetcount;
            int max_possiblefreq = targetcount + min(need_conversion, numOperations);
            result = max(result, max_possiblefreq);
        }
        return result;
    }
};