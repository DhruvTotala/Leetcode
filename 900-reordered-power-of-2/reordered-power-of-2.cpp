class Solution {
public:

    string getstring(int n) {
          string s = to_string(n);
          sort(s.begin(), s.end());
          return s;
    }

    bool reorderedPowerOf2(int n) {
        string s = getstring(n);
        
        for(int i = 0; i <= 29; i++) {
            if(s == getstring(1 << i)) {
                return true;
            }
        }
        return false;
    }
};