#include <iostream>
#include <string>

using namespace std;
// never use non-dynamic programming method, too many condition need to consider
// following code only can pass 90/100 test cases
class Solution {
public:
    bool isInterLeave(string s1, string s2, string s3) {
        int ind1, ind2, ind3;
        int len1, len2, len3;
        int same;
        ind1 = ind2 = ind3 = 0;
        len1 = s1.length();
        len2 = s2.length();
        len3 = s3.length();
        //if (len1 == len2 == len3 == 0)
        if (len1 == 0 && len2 == 0 && len3 == 0)
            return true;
        same = 0;
        for (ind3 = 0; ind3 < len3; ind3++) {
            if (ind1 == len1) {
                if (s2.substr(ind2) == s3.substr(ind3))
                    return true;
                else {
                    if (same > 0) {
                        ind1 -= same;
                        ind2 += same;
                        same = 0;
                        if (s2[ind2] == s3[ind3])
                            ind2++;
                        else if (s1[ind1] == s3[ind3])
                            ind1++;
                        else
                            return false;
                        continue;
                    }
                    return false;
                }
            }
            if ((ind2 + same) == len2) {
                if (s1.substr(ind1-same) == s3.substr(ind3))
                    return true;
                else
                    return false;
            }

            if (s1[ind1] != s3[ind3] && s2[ind2] != s3[ind3]) {
                if (same == 0)
                    return false;
                else {
                    ind2 += same;
                    ind1 -= same;
                    same = 0;
                }
            }

            if (s1[ind1] == s3[ind3]) {
                cout<<s1[ind1]<<"x"<<endl;  
                if (s1[ind1] == s2[ind2+same]) {
                    same++;
                }
                else if(same > 0 && s1[ind1] != s2[ind2+same] && s1[ind1] != s2[ind2]) {
                    same = 0;
                }
                ind1++;
                cout<<same<<"z"<<endl;
                continue;
            }
            if (s2[ind2] == s3[ind3]) {
                cout<<s2[ind2]<<"y"<<endl;
                ind2++;
                if (same > 0)
                    same--;
                continue;
            }
            return false;
        }
        return false; // prevent string s3 end first
    }
};


int main() {
    string s1 = "aabd";
    string s2 = "abdc";
    string s5 = "aabdabcd";
    string s3 = "aadbbcbcac";
    string s4 = "aadbbbaccc";
    cout<<s1.substr(4)<<endl;
    Solution sl;
    cout<<sl.isInterLeave(s1,s2,s3)<<endl;
    cout<<sl.isInterLeave(s1,s2,s4)<<endl;
    cout<<sl.isInterLeave(s1,s2,s5)<<endl;
    return 1;
}
