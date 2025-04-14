class Solution {
    public:
        int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
            int good = 0;
            for (int i = 0 ; i < arr.size() - 2 ; i++) {
                for (int k = i + 2 ; k < arr.size() ; k++) {
                    if (abs(arr[k] - arr[i]) > c) continue;
                    for (int j = i + 1; j < k ; j++) 
                    if (abs(arr[i] - arr[j]) <= a && 
                        abs(arr[j] - arr[k]) <= b) 
                        ++good; 
                }
            }
        return good;
    }
};