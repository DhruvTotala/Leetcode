class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
      int n1 = nums1.size();
      int n2 = nums2.size();

      map<int, int> mp;
      vector<vector<int>> ans;
      for(int i = 0; i < n1; i++){
        int id = nums1[i][0];
        int v = nums1[i][1];
        mp[id] += v;
      }  
      for(int i = 0; i < n2; i++){
        int id = nums2[i][0];
        int v = nums2[i][1];
        mp[id] += v;
      }
      for(auto it : mp){
        int num = it.first;
        int frqs = it.second;
        ans.push_back({num, frqs});
      }
      return ans;
    }
};