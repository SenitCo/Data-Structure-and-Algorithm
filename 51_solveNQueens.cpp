/*@Description: N-Queens
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a 
queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

/**
利用数组tmp记录旗子在棋盘中的位置，例如tmp[i]=j表示第i行第j列放置棋子，得到所有可能的布棋组合后，
再逐一生成对应的棋盘（字符串），利用tmp[i]=j表示棋子位置而不是二维数组board[i][j]='Q'这种方式，
可避免在多方向（列、斜对角）搜索确认是否存在冲突情况，而只需要考虑是否满足一定的数学条件
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> pos;
        vector<int> tmp(n, 0);
        backtrack(pos, tmp, n, 0);
        for(int i = 0; i < pos.size(); i++)
        {
            vector<string> board(n, string(n, '.'));
            for(int j = 0; j < pos[i].size(); j++)
            {
                int index = pos[i][j];
                board[j][index] = 'Q';
            }
            result.push_back(board);
        }
        return result;
    }
private:
    void backtrack(vector<vector<int>>& pos, vector<int>& tmp, int n, int t)
    {
        if(t == n)
            pos.push_back(tmp);
        else
        {
            for(int i = 0; i < n; i++)
            {
                bool flag = false;
                tmp[t] = i;
                for (int k = 0; k < t; k++)
                {
                	// (*)利用这个关系式判断是否冲突，而不需要多方向搜索
                    if (tmp[t] == tmp[k] || abs(t - k) == abs(tmp[t] - tmp[k]))		
                    {
                        flag = true;
                        break;
                    }                    
                }
                if (!flag)	//如果t = 0或者不存在冲突的情况，则继续递归
                    backtrack(pos, tmp, n, t + 1);
            }
        }
    }
};


/**
和上述方案一样，只是将判断条件单独抽离出来
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<int>> pos;
        vector<int> tmp(n, 0);
        backtrack(pos, tmp, n, 0);
        for(int i = 0; i < pos.size(); i++)
        {
            vector<string> board(n, string(n, '.'));
            for(int j = 0; j < pos[i].size(); j++)
            {
                int index = pos[i][j];
                board[j][index] = 'Q';
            }
            result.push_back(board);
        }
        return result;
    }
private:
    void backtrack(vector<vector<int>>& pos, vector<int>& tmp, int n, int t)
    {
        if(t == n)
            pos.push_back(tmp);
        else
        {
            for(int i = 0; i < n; i++)
            {
                tmp[t] = i;
                if (isValid(tmp, t))
                    backtrack(pos, tmp, n, t + 1);
            }
        }
    }
    
    bool isValid(vector<int>& tmp, int t)
    {
        for (int k = 0; k < t; k++)
        {
            if (tmp[t] == tmp[k] || abs(t - k) == abs(tmp[t] - tmp[k]))
            {
               return false;
            }                    
        }
        return true;
    }
};

/**
利用vector<string> board考虑棋盘的布局是否冲突，需要多方向搜索，时间效率不高
*/
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';	//回溯后要将对应位置归位
            }
    }
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};

/**
Use flag vectors as bitmask, 4ms:
The number of columns is n, the number of 45° diagonals is 2 * n - 1, the number of 135° diagonals is also 
2 * n - 1.  When reach [row, col], the column No. is col, the 45° diagonal No. is row + col and the 135° diagonal 
No. is n - 1 + col - row. We can use three arrays to indicate if the column or the diagonal had a queen before, 
if not, we can put a queen in this position and continue.

NOTE: Please don't use vector<bool> flag to replace vector<int> flag in the following C++ code. In fact, vector<bool> 
is not a STL container. You should avoid to use it. You can also get the knowledge from here and here.

  *    | | |                / / /             \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \
  *    O O O               O O O               O O O
  *    | | |              / / / /             \ \ \ \ 
  *    O O O               O O O               O O O
  *    | | |              / / /                 \ \ \
  *   3 columns        5 45° diagonals     5 135° diagonals    (when n is 3)
  设置三个方向的标志位（列、45°对角、135°对角，行不用考虑，显然不会在同一行放置棋子；列标志位一共有n个，对角标志位为2n-1个），
  每次只需判断该坐标点的三个标志位是否被占用，若没被占用，则在该处放置棋子，并将对应的三个标志位置0，表示已被占用，并继续递归；
  否则考虑下一个坐标或者回溯（该轮遍历结束）。利用标志位的方式减少了不必要的搜索时间，也可将三个标志位放到同一个数组中，遍历的
  时候能够有效地区分即可。
****/
class Solution {
public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        std::vector<int> flag_col(n, 1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solveNQueens(res, nQueens, flag_col, flag_45, flag_135, 0, n);
        return res;
    }
private:
    void solveNQueens(std::vector<std::vector<std::string> > &res, std::vector<std::string> &nQueens, std::vector<int> &flag_col, std::vector<int> &flag_45, std::vector<int> &flag_135, int row, int &n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col != n; ++col)
            if (flag_col[col] && flag_45[row + col] && flag_135[n - 1 + col - row]) {
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 0;
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, flag_col, flag_45, flag_135, row + 1, n);
                nQueens[row][col] = '.';
                flag_col[col] = flag_45[row + col] = flag_135[n - 1 + col - row] = 1;
            }
    }
};