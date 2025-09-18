class Solution {
public:

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    int myAtoi(string s) {
        int i = 0;
        int num = 0;
        int sign = 1; // by default positive
        // 1. white spaces
        while(i < s.size() && s[i] == ' ') {
            i += 1;
        }

        // 2.Signedness
        if(i < s.size()) {
            if(s[i] == '-') {
                sign = -1;
                i += 1;
            } else if(s[i] == '+') {
                i += 1;
            }
        }
        
        //3. Conversion
        while(i < s.size() && isDigit(s[i])) {
            int digit = s[i] - '0';


            //4. Rounding

            if(num == INT_MAX / 10) {
                if(sign == 1) {
                    if(digit >= 7) return INT_MAX;
                }
                else if(sign == -1) {
                    if(digit >= 8) return INT_MIN;
                }
            }
            if(num > INT_MAX / 10) {
                if(sign == 1) return INT_MAX;
                else return INT_MIN;
            }
            num = num * 10 + digit;
            i += 1;
        }


        return sign * num;


    }
};