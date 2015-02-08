#include "../common/comm.h"
class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> index;
        string res = "";
        int len = s.size();
        int start = 0;
        int end = 0;
        int isPalin[len][len];
        memset(isPalin, 0, len*len*sizeof(int));
                
        for (int i =0; i < len; i++) {   // i stands for the length of step
            for (int j = 0; j < len; j++) {   // j stands for the start point
                if (i == 0) {
                    isPalin[j][j+i] = 1;
                    continue;
                }
                if (i + j >= len)
                    break;
                if (s[j] == s[i+j] && (i == 1 || isPalin[j+1][j+i-1])) {
                    isPalin[j][j+i] = 1;
                    if (i > (start - end)) {
                        start = j;
                        end = j+i;
                    }
                }
            }
        }
        res = s.substr(start, end-start+1);
        return  res;
    }
};
