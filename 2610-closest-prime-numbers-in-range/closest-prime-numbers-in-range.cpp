class Solution {
public:

    vector <bool> Sievehelper(int right){
       vector<bool> isprime(right + 1, true);
       isprime[0] = false;
       isprime[1] = false;
       for(int i = 2; i * i <= right; i++){
          if(isprime[i] == true){
            for(int j = 2; i * j <= right; j++){
                isprime[i * j] = false;
            }
          }
       }
       return isprime;
    }

    vector<int> closestPrimes(int left, int right) {
        vector <bool> isprime = Sievehelper(right);
        vector <int> ans;
        for(int i = left; i <= right; i++){
            if(isprime[i] == true) ans.push_back(i);
        }
        int min_diff = INT_MAX;
        vector <int> result = {-1, -1};
        for(int i = 1; i < ans.size(); i++){
            int diff = ans[i] - ans[i - 1];
            if(diff < min_diff){
               min_diff = diff;
               result = {ans[i - 1], ans[i]}; 
            }
    }
    return result;
    }
};