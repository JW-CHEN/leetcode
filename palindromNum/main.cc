#include "../common/comm.h"
class Solution {
public:
    bool isPalindrome(int x) {
        int i = 0;
        if (x < 10 && x >= 0) return true;
        if (x == INT_MIN || x < 0) return false;
        int temp = x;
        while (temp > 0) {
            i = i*10 + temp%10;
            temp /= 10;
        }
        return (i == x);
    }
};
