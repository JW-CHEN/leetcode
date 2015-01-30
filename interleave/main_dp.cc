#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1, len2, len3;
        len1 = s1.length();
        len2 = s2.length();
        len3 = s3.length();
        // some simple corner case
        if (len1 == 0 && len2 == 0 && len3 == 0)
            return true;
        if (len1 + len2 != len3)
            return false;
        if (len1 == 0)
            return (s2==s3);
        if (len2 == 0)
            return (s1==s3);
        /*  Make it as convention:
            array is constructed with one more element correspond to "null element"
            index in the "match" or "memo" should be start from 1
            index in the original string still start from 0
        */
        int **match = new int*[len1+1];
        int i, j;
        for (i = 0; i < len1+1; i++) {
            match[i] = new int[len2+1];
            for (j = 0; j < len2+1; j++) {
                match[i][j] = 0;
            }
        }
        // initialization for "null element" scenario
        i = 1;
        while (s1[i-1] == s3[i-1]) {
            match[i][0] = 1;
            i++;
        }
        j = 1;
        while (s2[j-1] == s3[j-1]) {
            match[0][j] = 1;
            j++;
        }
        int ind1, ind2;
        for (ind1 = 1; ind1 <= len1; ind1++) {
            for (ind2 = 1; ind2 <= len2; ind2++) {
                if ((ind1+ind2) > len3)                     
                    return false;
                if ((s1[ind1-1] == s3[ind1+ind2-1] && match[ind1-1][ind2] == 1) || (s2[ind2-1] == s3[ind1+ind2-1] && match[ind1][ind2-1] == 1))
                    match[ind1][ind2] = 1;
            }   
        } 
        // remember "for loop" will have one more addition after the final comparison
        return match[ind1-1][ind2-1];
    }
};

int main() {
    string s1 = "aabcd";
    string s2 = "abcde";
    string s5 = "aabcdeabcd";
    Solution sl; 
    cout<<sl.isInterleave(s1,s2,s5)<<endl;
    return 1;
}

