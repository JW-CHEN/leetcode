#include "../common/comm.h"

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char* start = s;
        const char* ptr_p = p;
        const char* match = p;
        const char* ptr_s = s;
        int len_s = strlen(s);
        int len_p = strlen(p);
        int num_star_match = -1;
        while(1) {
            if (*ptr_s == '\0')
                break;
            if (*ptr_p == '?') {
                ptr_p++;
                ptr_s++;
            }
            else if (*ptr_p == '*') {
                match = ptr_p;
                start = ptr_s;
                ptr_p++;
                num_star_match = 0;
            }
            else {
                if (*ptr_p == *ptr_s) {
                    ptr_p++;
                    ptr_s++;
                }
                else {
                    if (num_star_match == -1)
                        return false;
                    ptr_p = match + 1;
                    num_star_match++;
                    ptr_s = start + num_star_match;
                    if (*ptr_s == '\0' && *ptr_p != '\0')
                        return false;
                }
            }
        }
        // Why this can pass, but if I use the (*ptr_s == '\0' && *ptr_p == '\0') to return true is wrong
        while (*ptr_p == '*') {ptr_p++;}
        return !*ptr_p;
    }
};

int main() {
    const char* s = "aaaaaaaaaaaaaaaaa";
    const char* p = "aaaaaaaaaaaaaaaaa****";
    Solution sl;
    cout<<sl.isMatch(s,p)<<endl;
    return 1;
}