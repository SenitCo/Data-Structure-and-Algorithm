/*@Description: Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X
*/

//广度优先遍历(BFS)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())    return;
        int height = board.size(), width = board[0].size();
        for(int i = 0; i < height; i++) //从左右边界开始搜索
        {
            if(board[i][0] == 'O')
                bfs(board, i, 0);
            if(board[i][width - 1] == 'O')
                bfs(board, i, width - 1);
        }
        
        for(int j = 0; j < width; j++)  //从上下边界开始搜索
        {
            if(board[0][j] == 'O')
                bfs(board, 0, j);
            if(board[height - 1][j] == 'O')
                bfs(board, height - 1, j);
        }
        
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'B')
                    board[i][j] = 'O';
            }
        }
        
    }
private:
    void bfs(vector<vector<char>>& board, int i, int j)
    {
        int height = board.size(), width = board[0].size();
        queue<pair<int, int>> toVisit;
        board[i][j] = 'B';
        toVisit.push(make_pair(i, j));
        while(!toVisit.empty())
        {
            pair<int, int> cur = toVisit.front();
            toVisit.pop();
            if(cur.first > 0 && board[cur.first - 1][cur.second] == 'O')
            {
                toVisit.push(make_pair(cur.first - 1, cur.second));
                board[cur.first - 1][cur.second] = 'B';
            }
            if(cur.first < height - 1 && board[cur.first + 1][cur.second] == 'O')
            {
                toVisit.push(make_pair(cur.first + 1, cur.second));
                board[cur.first + 1][cur.second] = 'B';
            }
            if(cur.second > 0 && board[cur.first][cur.second - 1] == 'O')
            {
                toVisit.push(make_pair(cur.first, cur.second - 1));
                board[cur.first][cur.second - 1] = 'B';
            }
            if(cur.second < width - 1 && board[cur.first][cur.second + 1] == 'O')
            {
                toVisit.push(make_pair(cur.first, cur.second + 1));
                board[cur.first][cur.second + 1] = 'B';
            }
        } 
    }
};

//深度优先遍历(DFS)
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty())    return;
        int height = board.size(), width = board[0].size();
        for(int i = 0; i < height; i++)
        {
            if(board[i][0] == 'O')
                dfs(board, i, 0);
            if(board[i][width - 1] == 'O')
                dfs(board, i, width - 1);
        }
        
        for(int j = 0; j < width; j++)
        {
            if(board[0][j] == 'O')
                dfs(board, 0, j);
            if(board[height - 1][j] == 'O')
                dfs(board, height - 1, j);
        }
        
        for(int i = 0; i < height; i++)
        {
            for(int j = 0; j < width; j++)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'B')
                    board[i][j] = 'O';
            }
        }
        
    }
private:
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        int height = board.size(), width = board[0].size();
        if(i >= 0 && i < height && j >= 0 && j < width && board[i][j] == 'O')
        {
            board[i][j] = 'B';
            dfs(board, i - 1, j);
            dfs(board, i + 1, j);
            dfs(board, i, j - 1);
            dfs(board, i, j + 1);
        }
    }
};