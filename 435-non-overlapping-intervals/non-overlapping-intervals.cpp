class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int i = 0; 
        int j = 1;
        int count = 0;
        while(j < n) {
            vector <int> curr = intervals[i];
            vector <int> next = intervals[j];
            int cs = curr[0];
            int ce = curr[1];
            int ns = next[0];
            int ne = next[1];
            if(ce <= ns) { //No Overlap
               i = j;
               j++;
            } else if(ce <= ne) {
                j++;
                count++;
            } else if(ce > ne) {
                i = j;
                j++;
                count++;
            }
        }
        return count;
    }
};