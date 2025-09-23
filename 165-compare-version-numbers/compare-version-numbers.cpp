class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1), s2(version2);
        string token1, token2;
        
        while (!s1.eof() || !s2.eof()) {
            token1.clear();
            token2.clear();
            
            if (!getline(s1, token1, '.')) token1 = "0";
            if (!getline(s2, token2, '.')) token2 = "0";
            
            int num1 = stoi(token1);
            int num2 = stoi(token2);
            
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
        }
        return 0;
    }
};
