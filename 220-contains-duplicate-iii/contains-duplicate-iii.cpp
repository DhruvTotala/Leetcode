class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int k = indexDiff + 1 ;
        multiset<int> s ;
        for(int i = 0 ; i < nums.size() ; i++){
            s.insert(nums[i]) ;
            if(i >= k) s.erase(s.find(nums[i-k])) ;
            auto it = s.find(nums[i]) ;
            auto nextIt = next(it) ;
            auto prevIt = prev(it) ;
            if(nextIt != s.end() && (* nextIt - * it) <= valueDiff) return true ;
            if(it != s.begin() && (* it - * prevIt) <= valueDiff) return true ;
        }
        return false ;
    }
};