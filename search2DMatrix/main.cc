class Solution {
public:
    vector<int> getPos(int n, int col) {
        vector<int> ret(2,0);
        ret[0] = n/col;
        ret[1] = n%col;
        return ret;
    }

    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int row = matrix.size();
        if (row == 0)
            return false;
        int col = matrix[0].size();
        vector<int> pos;
        int start = 0, end = row*col-1;
        while (start <= end) {
            pos = getPos((start+end)/2, col);
            if (matrix[pos[0]][pos[1]] < target) 
                start = (start+end)/2 + 1;
            else if (matrix[pos[0]][pos[1]] > target)
                end = (start+end)/2 - 1;
            else
                return true;
        }
        return false;
    }
};