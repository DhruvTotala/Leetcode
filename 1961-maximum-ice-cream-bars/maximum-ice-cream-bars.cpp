class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int it : costs) {
            if(it > coins) break;
            ans++;
            coins -= it;
        }
        return ans;
    }
};