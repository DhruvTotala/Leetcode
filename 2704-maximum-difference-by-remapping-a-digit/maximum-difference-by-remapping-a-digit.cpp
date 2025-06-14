class Solution {
public:
    int minMaxDifference(int num) {
        string s1 = to_string(num);
        string s2 = s1;

        int idx = s1.find_first_not_of('9');
        if(idx != string :: npos) {
        char ch = s1[idx];
        replace(s1.begin(), s1.end(), ch, '9'); //max number calculation
    }
        char ch = s2[0];
        replace(s2.begin(), s2.end(), ch, '0');

        return stoi(s1) - stoi(s2);  
    }
};