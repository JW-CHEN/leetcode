#include "../common/comm.h"

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0, res = 0;
        if (*s == '\0') return 0;
        while (*s != '\0') {
            if (*s != ' ') {
                len++;
                s++;
            }
            else if (*s == ' ') {
                res = len;
                len = 0;
                while (*(++s) == ' ') {}
            }
        }
        if (*(s-1) != ' ')
            res = len;
        return res;
    }
};

int main() {
    Solution sl;
    const char* s = "Hello Worl";
    cout<<sl.lengthOfLastWord(s)<<endl;
    return 1;
}