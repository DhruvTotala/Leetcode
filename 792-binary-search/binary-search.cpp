class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = 0;
        int low = 0;
        int high = n - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};