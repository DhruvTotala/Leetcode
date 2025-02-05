#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        int count = 0;
        unordered_map<char, int> mp1, mp2;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) count++;
            if (count > 2) return false;

            mp1[s1[i]]++;
            mp2[s2[i]]++;
        }

        return mp1 == mp2;
    }
};
