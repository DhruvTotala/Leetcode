class Solution {
public:
    double angleClock(int hour, int minutes) {
        double d = abs(60 * (hour % 12) - 11 * minutes) / 2.0;
        return min(d, 360.0 - d);
    }
};