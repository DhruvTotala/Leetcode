class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector <int> arr;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                arr.push_back(matrix[i][j]);
            }
        }
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(arr[mid] == target) return true;
            else if(arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};