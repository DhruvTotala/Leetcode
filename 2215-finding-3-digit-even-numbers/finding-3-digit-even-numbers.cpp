class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector <int> ans;
        unordered_map <int, int> mpp;
        for(auto &digit : digits) mpp[digit]++;
        for(int i = 1; i <= 9; i++) {
            if(mpp[i] == 0) continue;
            mpp[i]--;
            for(int j = 0; j <= 9; j++) {
               if(mpp[j] == 0) continue;
               mpp[j]--;
               for(int k = 0; k <= 8; k += 2) {
                  if(mpp[k] == 0) continue;
                  mpp[k]--;

                  int num = 100*i + 10*j + k;
                  ans.push_back(num);
                  mpp[k]++;
               }
               mpp[j]++; 
            }
            mpp[i]++;
        }
        return ans;
    }
};