class NumberContainers {
public:
    map<int, int> mp;
    map<int, set<int>> mp1;   
    NumberContainers() {}
    void change(int index, int number) {
        if (mp.count(index)) {
            int prevnum = mp[index];
            mp1[prevnum].erase(index);
            if (mp1[prevnum].empty()) mp1.erase(prevnum);   
        }
        mp[index] = number;
        mp1[number].insert(index);
    }
    int find(int number) {
        if (mp1.count(number) && !mp1[number].empty()) { 
            return *mp1[number].begin();
        }
        return -1;
    }
};
