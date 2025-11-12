class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0;
        int balance = 0;
        int n = gas.size();
        int total_gas = 0;
        int total_cost = 0;
        for(int i = 0; i < n; i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            balance += gas[i] - cost[i];
            if(balance < 0) {
                ans = i + 1;
                balance = 0;
            }
        }
        return total_gas < total_cost ? -1 : ans;
    }
};