/*@Description: Valid Sudoku
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
A partially filled sudoku which is valid.
Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
*/

/****是否为合法数盘，数组操作，遍历检查(brute force)***/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> rowFlag = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> colFlag = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<bool>> cellFlag = vector<vector<bool>>(m, vector<bool>(n, false));
        int c = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] > '0' && board[i][j] <= '9')
                {
                    c = board[i][j] - '1';
                    if(rowFlag[i][c] || colFlag[c][j] || cellFlag[3 * (i / 3) + j / 3][c])
                        return false;
                    rowFlag[i][c] = true;
                    colFlag[c][j] = true;
                    cellFlag[3 * (i / 3) + j / 3][c] = true;
                }
            }
        }
        return true;
    }
};

bool isValidSudoku(vector<vector<char> > &board)
{
    int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};
    
    for(int i = 0; i < board.size(); ++ i)
        for(int j = 0; j < board[i].size(); ++ j)
            if(board[i][j] != '.')
            {
                int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                if(used1[i][num] || used2[j][num] || used3[k][num])
                    return false;
                used1[i][num] = used2[j][num] = used3[k][num] = 1;
            }
    
    return true;
}
