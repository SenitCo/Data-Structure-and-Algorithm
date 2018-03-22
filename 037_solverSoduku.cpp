/*@Description: Sudoku Solver
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.
*/

/**
数独与Permutations 全排列，Combinations 组合项， N-Queens N皇后问题类似，均可采用回溯法求解
*/

/**
对于每个需要填数字的格子带入1到9，每代入一个数字都判定其是否合法，如果合法就继续下一次递归，结束时把数字设回'.'，
判断新加入的数字是否合法时，只需要判定当前数字是否合法，不需要判定这个数组是否为数独数组，因为之前加进的数字都是
合法的，这样可以使程序更加高效一些
*/
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        if(board.empty() || board.size() != 9 || board[0].size() != 9)
            return;
        search(board, 0, 0);
    }
    
    bool search(vector<vector<char>>& board, int i, int j)
    {
        if(i == 9)  return true;
        if(j >= 9)  return search(board, i + 1, 0);
        if(board[i][j] == '.')
        {
            for(int k = 0; k < 9; k++)
            {
                board[i][j] = (char)(k + '1');
                if(isValid(board, i, j)) 		//如果新加数字合法，则继续递归      
                {
                    if(search(board, i, j + 1)) 
                        return true;
                }
                board[i][j] = '.';	//新加数字不合法或回溯至此时，将数字设为空
            }
        }
        else
        {
            return search(board, i, j + 1);
        }
        return false;
    }
    
    //判断新加的数字是否合法，只需判断该数字所在行、列以及块，不需遍历整个数盘
    bool isValid(vector<vector<char>>& board, int i, int j)		
    {
        for(int row = 0; row < 9; row++)
        {
            if(i != row && board[i][j] == board[row][j])
                return false;
        }
        
        for(int col = 0; col < 9; col++)
        {
            if(j != col && board[i][j] == board[i][col])
                return false;
        }
        
        for(int row = i / 3 * 3; row < i / 3 * 3 + 3; row++)
        {
            for(int col = j / 3 * 3; col < j / 3 * 3 + 3; col++)
            {
                if((row != i || col != j) && board[i][j] == board[row][col])
                    return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) 
    {
        if(board.empty() || board.size() != 9 || board[0].size() != 9)
            return;
        search(board);
    }

	bool search(vector<vector<char> > &board) 
	{
	    for (int row = 0; row < 9; ++row) 
	    {
	        for (int col = 0; col < 9; ++col) 
	        {
	            if (board[row][col] == '.') 
	            {
	                for (int i = 1; i <= 9; ++i)
	                {
	                    board[row][col] = '0' + i;

	                    if (isValid(board, row, col)) 
	                        if (search(board)) 
	                            return true;                    
	                    board[row][col] = '.';
	                }
	                return false;
	            }
	        }
	    }
	    return true;
	}

	bool isValid(vector<vector<char>>& board, int i, int j)		
	{
	    for(int row = 0; row < 9; row++)
	    {
	        if(i != row && board[i][j] == board[row][j])
	            return false;
	    }
	    
	    for(int col = 0; col < 9; col++)
	    {
	        if(j != col && board[i][j] == board[i][col])
	            return false;
	    }
	    
	    for(int row = i / 3 * 3; row < i / 3 * 3 + 3; row++)
	    {
	        for(int col = j / 3 * 3; col < j / 3 * 3 + 3; col++)
	        {
	            if((row != i || col != j) && board[i][j] == board[row][col])
	                return false;
	        }
	    }
	    return true;
	}

};