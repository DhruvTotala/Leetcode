class Solution {
public:
    int getsum(int num){
        int sum = 0;
        while(num > 0){
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
    int n = nums.size();
    int ans = -1;
    unordered_map <int, int> mp;
    for(int i = 0; i < n; i++){
        int sum = getsum(nums[i]);
        if(mp.count(sum)) ans = max(ans, nums[i] + mp[sum]);
        mp[sum] = max(nums[i], mp[sum]);
        }
        return ans;
    }
};