class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++){
        for(int j = n - 1; j > i; j--){
            int prod = nums[i] * nums[j];
            unordered_set <int> st;
            for(int k = i + 1; k < j; k++){
                if(prod % nums[k] == 0){
                    int dval = prod / nums[k];
                    if(st.count(dval)) ans++;
                    st.insert(nums[k]);
                }
            }
        }
    }
    return ans * 8;
    }
};