class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if (row == 0)
            return ;
        int col = matrix[0].size();
        int firRowZero = 0, firColZero = 0;
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                firColZero = 1;
                break;
            }
        }
        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == 0) {
                firRowZero = 1;
                break;
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    break;
                }
            }
        }
        for (int j = 1; j < col; j++) {
            for (int i = 1; i < row; i++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    break;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if (firRowZero == 1) {
            for (int j = 0; j < col; j++)
                matrix[0][j] = 0;
        }
        if (firColZero == 1) {
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }
    }
};