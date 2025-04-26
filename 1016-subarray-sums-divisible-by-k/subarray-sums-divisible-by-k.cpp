class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> mp;
        mp[0] = 1; // starting will be zero only
        int result = 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            int modul = (sum % k);
            if(modul < 0) modul += k;
            if(mp.count(modul)){
                result += mp[modul];
            }
            mp[modul] ++;
        }
        return result;
    }
};