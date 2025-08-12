class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0;
        for(; i<arr.size(); ++i)
            if(arr[i] <= k) 
                ++k;
            else 
                break;
        return k;
    }
};