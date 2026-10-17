class Solution {
public:
    int digit_s(int num) {
      int sum = 0;
      while(num) {
        sum += num % 10;
        num /= 10;
      }
      return sum;
    }
    
    int minSwaps(vector<int>& nums) {
      int n = nums.size();
      vector <pair<pair<int, int>,int>> nums_s;
      for(int i = 0; i < n; i++) {
        nums_s.push_back({{digit_s(nums[i]) , nums[i]}, i});
      }
      sort(nums_s.begin(), nums_s.end());
      
      vector <bool> v(n, false);
      int s = 0;
      
      for(int i = 0; i < n; i++) {
        if(v[i] || nums_s[i].second == i) continue;
        
        int c = 0;
        int j = i;
        while(!v[j]) {
          v[j] = true;
          j = nums_s[j].second;
          c++;
        }
        if(c > 1) s += (c - 1);
      }
      return s;
    }
};