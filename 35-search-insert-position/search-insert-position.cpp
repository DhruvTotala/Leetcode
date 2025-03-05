class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0;
        int r = n - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(arr[mid] < target) l = mid + 1;
            else if(arr[mid] > target) r = mid - 1;
            else if(arr[mid] == target) return mid; 
        }
        return l;
    }
};