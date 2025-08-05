class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = fruits.size();
        for(int i = 0; i < n; i++) {
            int ans = 1;
            for(int j = 0; j < n; j++) {
                if(fruits[i] <= baskets[j]) {
                   baskets[j] = 0;
                   ans = 0;
                   break;
                }
            }
            count += ans;
        }
        return count;
    }
};