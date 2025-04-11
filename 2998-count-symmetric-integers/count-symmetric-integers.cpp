class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i <= high; i++) {
            string s = to_string(i);
            int n = s.size();
            if(n % 2 != 0) continue;
            else {
                int half = n / 2;
                int l_sum = 0;
                int r_sum = 0;
            for (int i = 0; i < half; ++i)
                 l_sum += s[i] - '0';

            for (int i = half; i < n; ++i)
                r_sum += s[i] - '0';

           if (l_sum == r_sum) count ++;
            }
        }
        return count;
    }
};