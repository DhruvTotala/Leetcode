class Solution {
public:
    typedef pair<int, int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> mp;
        for(int i = 0; i < n; i++) mp[nums[i]]++;

        priority_queue<p, vector<p>, greater<p>> pq;
        for(auto &it : mp) {
            int val = it.first;
            int frq = it.second;
            pq.push({frq, val});
            if(pq.size() > k) pq.pop();
        }
        vector <int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};