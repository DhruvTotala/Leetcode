class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // Use backtracking to generate all subsets and calculate their XOR sums
        int result = 0;
        generateSubSets(nums,0,0,result);
        return result;
    }
private:
    void generateSubSets(vector<int>& nums , int index , int currentXOR , int& totalSum) {
        // Base case: we've processed all elements
        if (index == nums.size()) {
            totalSum += currentXOR;
            return; 
        }

        // Option 1: Include the current element in the subset
        generateSubSets(nums , index + 1 , currentXOR ^ nums[index] , totalSum);

        // Option 2: Exclude the current element from the subset
        generateSubSets(nums , index + 1 , currentXOR , totalSum);
    }
};