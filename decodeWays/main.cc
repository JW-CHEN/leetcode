#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        cout<<len<<endl;
        if (len == 0)
            return 0;
        int *res = new int[len+1];
        for (int i = 0; i < len+1; i++) {
            res[i] = 0;
        }
        if (s[0] != '0') {
            res[0] = 1;
            res[1] = 1;
        }
        for (int i = 2; i < len+1; i++) {
            if (s[i-1] != '0') 
                res[i] += res[i-1];
            if (s[i-2] == '2' && s[i-1] <= '6' || s[i-2] == '1') {
                res[i] += res[i-2];
            }
        }
        return res[len];
    }
};


int main() {
    Solution sl;
    string s = "10";
    cout<<sl.numDecodings(s)<<endl;
    return 1;
}
