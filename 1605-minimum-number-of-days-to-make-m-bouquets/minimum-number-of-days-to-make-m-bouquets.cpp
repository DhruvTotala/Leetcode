class Solution {
public:

    bool ispossible(vector <int>& bloomDay, int mid, int m, int k) {
        int bloom_flower = 0;
        int no_of_bouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++) {
            if(bloomDay[i] <= mid) {
                bloom_flower++;
            } else {
                no_of_bouquets += (bloom_flower / k);
                bloom_flower = 0;
            }
        }
        no_of_bouquets += (bloom_flower / k);
        return no_of_bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * k > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(ispossible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};