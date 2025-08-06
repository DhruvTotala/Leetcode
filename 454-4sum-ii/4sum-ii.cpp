class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map <int, int> mp;
        for(int num : nums1) {
            for(int num2 : nums2) {
                int sum = num + num2;
                mp[sum]++;
            }
        }

        for(int num : nums3) {
            for(int num2 : nums4) {
                int sum = -(num + num2);
                if(mp.count(sum)) count += mp[sum];
            }
        }
        return count;
    }
};