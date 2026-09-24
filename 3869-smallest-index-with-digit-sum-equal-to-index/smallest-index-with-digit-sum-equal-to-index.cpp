class Solution {
public:
    int single_digit(int x) {
        int sum = 0;
        while(x > 0) {
            sum += x % 10;
            x /= 10; 
        }
        return sum;
    }
    
    int smallestIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int num = single_digit(nums[i]);
            if(num == i) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};