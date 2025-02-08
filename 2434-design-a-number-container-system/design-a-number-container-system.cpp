#include <map>
#include <set>

class NumberContainers {
public:
    std::map<int, int> mp;              // Maps index -> number
    std::map<int, std::set<int>> mp1;   // Maps number -> sorted indices

    NumberContainers() {}

    void change(int index, int number) {
        // If index already has a number, remove it from mp1 (reverse mapping)
        if (mp.count(index)) {
            int prevnum = mp[index];
            mp1[prevnum].erase(index);
            if (mp1[prevnum].empty()) {
                mp1.erase(prevnum);  // Clean up empty sets
            }
        }
        // Update mappings
        mp[index] = number;
        mp1[number].insert(index);
    }

    int find(int number) {
        if (mp1.count(number) && !mp1[number].empty()) { 
            return *mp1[number].begin(); // Return the smallest index
        }
        return -1; // If number is not found
    }
};
