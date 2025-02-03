class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    int l = 1;
    int increase_count = 1;
    int decrease_count = 1;
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] > nums[i - 1]){
        increase_count += 1;
        decrease_count = 1;
        }    
        else if(nums[i] < nums[i - 1]){
        decrease_count += 1;
        increase_count = 1;
        } 
        else {
            increase_count = 1;
            decrease_count = 1;
        }   
    l = max(l, max(increase_count, decrease_count)); 
    } 
    return l;
    }
};