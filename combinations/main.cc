#include "../common/comm.h"

/*backtracking psudo_code

boolean solve(Node n) {
    if n is a leaf node {
        if the leaf is a goal node, return true
        else return false
    } else {
        for each child c of n {
            if solve(c) succeeds, return true
        }
        return false
    }

}
*/

class Solution {
private:
    int nn, kk;
public:
    void combineHelper(int x, int &index, vector<int> &elem, vector<vector<int> > &res) {
        // meet the leaf node, add to the final result
        if (index == kk) {
            res.push_back(elem);
        }
        else {
            // pre-define the range of the first element in each level
            for (int i = x; i <= nn - kk + 1 + index; i++) {
                elem[index] = i;
                // move to next level of tree
                index++;
                combineHelper(i+1, index, elem, res);
                // backtrace to upper level
                index--;
            }
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        // elem size is known, so do not push or pop elem
        vector<int> elem(k, 0);
        nn = n;
        kk = k;
        int index = 0;
        combineHelper(1, index, elem, res);
        return res;
    }
};

int main() {
	cout<<"Hello World!"<<endl;
	return 1;
}