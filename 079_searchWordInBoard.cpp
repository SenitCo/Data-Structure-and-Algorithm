/*@Description: Word Search
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those 
horizontally or vertically neighboring. The same letter cell may not be used more than once.
For example,
Given board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/**
先找到word中第一个字符在board中的所有位置，存入一个数组，然后从每个位置开始搜索，并用另一个数组存储
已经搜索过的位置，效率较低，每次都要在数组中查找是否已经访问过该位置
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> start;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                    start.push_back(make_pair(i, j));
            }
        }
        
        for (int i = 0; i < start.size(); i++)
        {
            vector<pair<int, int>> visited;
            if (backtrack(board, word, start[i], visited, 1))
                return true;
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string& word, pair<int, int> pos, vector<pair<int, int>> visited, int count)
    {
        vector<pair<int, int>>::iterator iter = find(visited.begin(), visited.end(), pos);
        if (iter != visited.end())
            return false;
        visited.push_back(pos);
        if (count == word.size())
            return true;
        int row = pos.first, col = pos.second;
        if (row > 0 && board[row - 1][col] == word[count])	//坐标的越界条件可以放到一起统一处理
            if (backtrack(board, word, make_pair(row - 1, col), visited, count + 1))
                return true;
        if (col > 0 && board[row][col - 1] == word[count])
            if (backtrack(board, word, make_pair(row, col - 1), visited, count + 1))
                return true;
        if (row < board.size() - 1 && board[row + 1][col] == word[count])
            if (backtrack(board, word, make_pair(row + 1, col), visited, count + 1))
                return true;
        if (col < board[0].size() - 1 && board[row][col + 1] == word[count])
            if (backtrack(board, word, make_pair(row, col + 1), visited, count + 1))
                return true;
        visited.pop_back();
        return false;
    }
};

/**
定义一个标志数组visited，如果位置(i, j)被访问过，则令visited[i][j] = 0
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {	//第一个判断条件可不要
                if (board[i][j] == word[0] && backtrack(board, word, i, j, visited, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, vector<vector<int>>& visited, int count)
    {
        if (count == word.size())
            return true;
        //将所有判断条件集中处理
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[i].size() - 1 || visited[i][j] || board[i][j] != word[count])
            return false;
        visited[i][j] = 1;
        if (backtrack(board, word, i - 1, j, visited, count + 1)
            || backtrack(board, word, i, j - 1, visited, count + 1)
            || backtrack(board, word, i + 1, j, visited, count + 1)
            || backtrack(board, word, i, j + 1, visited, count + 1))
            return true;
        visited[i][j] = 0;
        return false;
    }
};

/**
无需额外的存储空间表示元素是否访问过，若访问某元素，直接将其赋值为一个特殊字符，并在回溯时将其复原
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (backtrack(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j, int count)
    {
        if (count == word.size())
            return true;
        if (i < 0 || j < 0 || i > board.size() - 1 || j > board[i].size() - 1 || board[i][j] != word[count])
            return false;
        board[i][j] = '?';
        if (backtrack(board, word, i - 1, j, count + 1)
            || backtrack(board, word, i, j - 1, count + 1)
            || backtrack(board, word, i + 1, j, count + 1)
            || backtrack(board, word, i, j + 1, count + 1))
            return true;
        board[i][j] = word[count];
        return false;
    }
};