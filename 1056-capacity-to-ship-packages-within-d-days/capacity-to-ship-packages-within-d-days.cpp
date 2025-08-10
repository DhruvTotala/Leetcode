class Solution {
public:

    bool iscapacity(vector<int>& weights, int days, int mid) {
        int cnt = 1;
        int ships = 0;
        for(int i = 0; i < weights.size(); i++) {
            if(ships + weights[i] <= mid) {
                ships += weights[i];
            } else {
                cnt++;
                ships = weights[i];
            }
        }
        if(cnt <= days) return true;
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int ans = -1;
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(), 0);
        while(l <= h) {
            int mid = (l + h) / 2;
            if(iscapacity(weights, days, mid)) {
                ans = mid;
                h = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        return ans;
    }
};