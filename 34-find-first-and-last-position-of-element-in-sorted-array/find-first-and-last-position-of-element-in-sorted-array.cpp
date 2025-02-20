class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    vector <int> ans;
    int l = 0;
    int r = n - 1;
    int fst = -1, lst = -1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(nums[mid] >= target) {
            if(nums[mid] == target) fst = mid;
            r = mid - 1;
        }
            else l = mid + 1;
    }
    ans.push_back(fst);
    l = 0, r = n - 1;
    while(l <= r){
         int mid = (l + r) / 2;
         if(nums[mid] <= target){
            if(nums[mid] == target) lst = mid;
            l = mid + 1;
         }
         else r = mid - 1;
    }
    ans.push_back(lst);
    return ans;
    }
};