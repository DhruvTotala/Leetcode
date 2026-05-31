class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long mass1 = mass;
        for(int num : asteroids) {
            if(num > mass1) return false;
            mass1 += num;
        }
        return true;
    }
};