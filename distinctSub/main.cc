#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        if (T.length() == 0)
            return 1;
        int sLen, tLen;
        int **memo;
        sLen = S.length();
        tLen = T.length();
        memo = new int*[tLen+1];
        // from right to left to compare
        // memo[i][j] means how much matches happens in S[0-i], T[0-j]
        for (int i = 0; i <= tLen; i++) {
            memo[i] = new int[sLen+1];
            for (int j = 0; j <= sLen; j++) {
                if (i == 0)
                    memo[i][j] = 1;
                else
                    memo[i][j] = 0;
                }
        }
        // do not recursively solve, just iteration
        for (int i = 1; i <= tLen; i++) {
            for (int j = 1; j <= sLen; j++) {
                if (T[i-1] != S[j-1])
                    memo[i][j] = memo[i][j-1];
                else {
                    memo[i][j] = memo[i-1][j-1] + memo[i][j-1];
                }
            }
        }
        return memo[tLen][sLen]; 
    }  
};


int main() {
    Solution sl;
    string S = "rabbbbit";
    string T = "rabbit";
    cout<<sl.numDistinct(S,T)<<endl;
    return 1;
}
