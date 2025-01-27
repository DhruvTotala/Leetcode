class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
    vector <int> ans;
    int rem = 1;
    for(int i = digits.size() - 1; i >= 0; i--){
        int sum = digits[i] + rem;
        rem = sum / 10;
        ans.push_back(sum % 10);
    }   
    if(rem) ans.push_back(rem); 
    reverse(ans.begin(), ans.end());
    return ans;
    }
};