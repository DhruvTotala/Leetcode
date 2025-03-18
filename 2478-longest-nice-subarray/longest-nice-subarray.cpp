class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                bool isNice = true;
                for (int k = i; k < j; k++) {
                    if ((nums[k] & nums[j]) != 0) {
                        isNice = false;
                        break;
                    }
                }
                
                if (isNice) maxLen = max(maxLen, j - i + 1); 
                else break;
            }
        }
        return maxLen;
    }
};
