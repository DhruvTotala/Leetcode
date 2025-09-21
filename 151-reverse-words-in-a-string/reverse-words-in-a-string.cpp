#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        // Step 1: Extract words (stringstream ignores multiple spaces)
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 2: Reverse the vector of words
        reverse(words.begin(), words.end());

        // Step 3: Join them with single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if(i != words.size() - 1) result += " ";
        }

        return result;
    }
};
