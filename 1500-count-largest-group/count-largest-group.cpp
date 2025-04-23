class Solution {
public:
    int findds(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        unordered_map <int, int> mp;
        int max_size = 0;
        int count = 0;
        for(int i = 1; i <= n; i++) {
            int digitsum = findds(i);
            mp[digitsum]++;
            if(mp[digitsum] == max_size) count ++;
            else if(mp[digitsum] > max_size) {
                max_size = mp[digitsum];
                count = 1;
            }
        }
        return count;
    }
};