#include <iostream>
#include <vector>

using namespace std;

// some error when use multiple submission
/* 
1. forget to pre-allocate space for two vector (line 20-21)
2. forget to initialize res=0 (line 19)
3. misunderstanding the problem, children donot care about its same value neighbor's # of candy. (delete some equal comparison condition between 26-27)
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        int sz = ratings.size();
        if (sz == 0)
            return 0;
        int res = 0;
        vector<int> ltor(sz,0);
        vector<int> rtol(sz,0);
        // find maximum length of monotonically decreasing series
        for (int i = 1; i < sz; i++) {
            // from left to right
            if (ratings[i-1] < ratings[i])
                ltor[i] = ltor[i-1] + 1;
            else
                ltor[i] = 0;
            // from right to left
            if (ratings[sz-i] < ratings[sz-1-i])
                rtol[sz-1-i] = rtol[sz-i] + 1;
            else
                rtol[sz-1-i] = 0;
        }
        // the bigger one of two direction max length determine how much candies itself can get.
        cout<<ltor[0]<<endl<<rtol[0];
        for (int i = 0; i < sz; i++) {
            res += (max(ltor[i], rtol[i]) + 1);
        }
        return res;
    }
};


int main() {
    Solution sl;
    vector<int> ratings;
    ratings.push_back(0);
    cout<<sl.candy(ratings)<<endl;
    return 1;
}
