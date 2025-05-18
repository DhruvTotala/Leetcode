class Solution {
public:
    unordered_map<string, int> dp;
  
    int helper(vector<string>& stickers, vector<vector<int>> mp,
               string target) {
        if (target == "") {
            return 0;
        }
        if(dp.count(target)) return dp[target];
        //  ["with","example","science"]
        // target= "ehat"
        int temp_ans = INT_MAX;
        int n = mp.size();
        vector<int> target_mp(26, 0);
        for (auto chr : target) {
            target_mp[chr - 'a']++;
        }

        for (int i = 0; i < n; i++) {
            if(mp[i][target[0]-'a']==0) continue;
        
            string new_target;
            for(int j=0;j<26;j++){
                if(target_mp[j]>mp[i][j]){
                    new_target += string(target_mp[j]- mp[i][j], 'a'+j);
                }
            }
            int temp=helper(stickers, mp,new_target);
            if(temp!=INT_MAX){
                temp_ans= min(temp_ans,1 +temp);
            }
        }
        dp[target]=temp_ans;
        return temp_ans;
    }
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> mp(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            for (auto chr : stickers[i]) {
                mp[i][chr - 'a']++;
            }
        }
        int ans = helper(stickers, mp, target);
        return ans==INT_MAX?-1:ans;
    }
};