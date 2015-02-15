#include "../common/comm.h"

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res;
        int sz = S.size();
        sort(S.begin(), S.begin()+sz);
        vector<int> elem;
        res.push_back(elem);
        int prev, scan;
        int currSize, preValue = INT_MIN, nextSize = 1;
        for (int i = 0; i < sz; i++) {
            currSize = nextSize;
            /* if dupliplicate occurs, only append curr data to the vector that created by previous data
                othersise, append curr data to all the original data in the res set */
            if (S[i] != preValue) {
                preValue = S[i];
                scan = 0;
            }
            else {
                scan = prev;
            }
            prev = currSize;
            while (scan < currSize) {
                elem = res[scan++];
                elem.push_back(S[i]);
                res.push_back(elem);
                /* This can be omitted, if the elem index can be calc right*/
                //elem.erase(elem.begin(), elem.end());
                nextSize++;
            }
        }
        return res;
    }
};