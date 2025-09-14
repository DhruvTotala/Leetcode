class Solution {
public:
    // Convert to lowercase
    string toLower(string s) {
        for (char &c : s) c = tolower(c);
        return s;
    }

    // Replace vowels with '*'
    string devowel(string s) {
        for (char &c : s) {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                c = '*';
            else
                c = lower;
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelError;

        // Build maps
        for (string &w : wordlist) {
            string lower = toLower(w);
            string dv = devowel(w);

            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = w;

            if (!vowelError.count(dv))
                vowelError[dv] = w;
        }

        vector<string> result;
        for (string q : queries) {
            if (exact.count(q)) {
                result.push_back(q);
            } else {
                string lower = toLower(q);
                string dv = devowel(q);

                if (caseInsensitive.count(lower)) {
                    result.push_back(caseInsensitive[lower]);
                } else if (vowelError.count(dv)) {
                    result.push_back(vowelError[dv]);
                } else {
                    result.push_back("");
                }
            }
        }

        return result;
    }
};
