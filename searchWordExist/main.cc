#include "../common/comm.h"

class Solution {
private:
    int row;
    int col;
    int len;
    int **visited;
    
public:
    bool existHelper(vector<vector<char> > &board, string word, int wInd, int r, int c) {
        if (wInd == len-1 && board[r][c] == word[wInd]) {
            return true;
        }
        if (board[r][c] != word[wInd])
            return false;
        visited[r][c] = 1;
        // search for four possible options at each level node
        if (r > 0 && !visited[r-1][c] && existHelper(board, word, wInd+1, r-1, c)) 
            return true;
        if (r < row - 1 && !visited[r+1][c] && existHelper(board, word, wInd+1, r+1, c)) 
            return true;
        if (c > 0 && !visited[r][c-1] && existHelper(board, word, wInd+1, r, c-1))
            return true;
        if (c < col - 1 && !visited[r][c+1] && existHelper(board, word, wInd+1, r, c+1))
            return true;
        visited[r][c] = 0;
        return false;
    }

    bool exist(vector<vector<char> > &board, string word) {
        len = word.length();
        row = board.size();
        col = board[0].size();
        if (len == 0)
            return true;
        visited = new int*[row];
        for (int i = 0; i < row; i++) {
            visited[i] = new int[col];
            for (int j = 0; j < col; j++)
                visited[i][j] = 0;
        }
        int r = 0, c = 0;
        while (1) {
            // search the tree level one options
            if (existHelper(board, word, 0, r, c))
                return true;
            if (c < col - 1)
                c++;
            else if (r < row - 1) {
                r++;
                c = 0;
            }
            else
                return false;
        }
    }
};

int main() {
    cout<<"Hello World!"<<endl;
    return 1;
}