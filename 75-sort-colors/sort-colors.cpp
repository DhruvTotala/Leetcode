class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector <int> arr(3);
        for(int i : nums){
            arr[i]++;
        }
        int j = 0;
        for(int i = 0; i < 3; i++){
            while(arr[i]){
                nums[j] = i;
                j++;
                arr[i]--;
            }
        }
    }
};