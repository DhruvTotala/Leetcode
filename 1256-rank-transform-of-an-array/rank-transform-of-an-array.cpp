class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map <int, int> mp;
        vector <int> tmp(arr);
        sort(tmp.begin(), tmp.end());
        int c = 1;
        for(int i = 0; i < tmp.size(); i++) {
            if(i > 0 && tmp[i] > tmp[i - 1]) {
                c++;
            }
            mp[tmp[i]] = c;
        }
        for(int i = 0; i < n; i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};