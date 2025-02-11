class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int i = s.find(part);
            if(i == string::npos) break;
            s.erase(i, part.size());
        }
        return s;
    }
};