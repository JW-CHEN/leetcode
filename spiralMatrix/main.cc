#include "../common/comm.h"

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int right = n, bottom = n, left = 0, top = 0;
        int count = 0, i = 0, j = 0;
        vector<vector<int> > res(n, vector<int> (n, 0));
        while (1) {
            if (count == n*n) break;

            for (; j < right; j++)
                res[i][j] = ++count;
            top++;
            i++;
            j--;
            if (count == n*n) break;
            for (; i < bottom; i++)
                res[i][j] = ++count;
            right--;
            j--;
            i--;
            if (count == n*n) break;
            for (; j >= left; j--)
                res[i][j] = ++count;
            bottom--;
            i--;
            j++;
            if (count == n*n) break;
            for (; i >= top; i--)
                res[i][j] = ++count;
            left++;
            j++;
            i++;
        }
        return res;
    }
};

int main() {
    Solution sl;
    vector<vector<int> > res;
    res = sl.generateMatrix(2);
    int row = res.size();
    int col = res[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout<<res[i][j];
        cout<<endl;
    }
    cout<<"Hello World"<<endl;
    return 1;
}