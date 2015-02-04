class Solution {
public:
    int atoi(const char *str) {
        long res = 0;
        int flag = 0;
        // skip all whitespace bits
        while (*str == ' ')
            str++;
        // look for sign bit
        if (*str == '-') {
            flag = 1;
            str++;
        }
        else if (*str == '+')
            str++;
        
        // check for first number bit
        if (*str > 57 || *str < 48)
            return 0;
        // skipp all most-significant bits 0
        while (*str != '\0' && *str == '0')
            str++;
        while (*str != '\0') {
            // skip any formed number later's non-number bits
            if (*str > 57 || *str < 48)
                return flag == 0 ? res : -res;
            // use long value to store the result, because it may exceed INT_MAX and do translate by itself.
            res = res*10 + (*str - 48);
            // if the string excess the range, return INT_MAX or INT_MIN.
            if (res > INT_MAX) {
                return flag == 0 ? INT_MAX : INT_MIN;
            }
            str++;
        }
        return flag == 0 ? res : -res;
    }
};
