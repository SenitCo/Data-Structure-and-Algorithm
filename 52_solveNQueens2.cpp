/*@Description: N-Queens II
Now, instead outputting board configurations, return the total number of distinct solutions.
*/

/**
无需得到每一种棋盘布局情况，只需统计有效的组合数
*/
class Solution {
public:
    int totalNQueens(int n) {
        int sum = 0;
        vector<int> tmp(n, 0);
        backtrack(tmp, n, 0, sum);
        return sum;
    }
private:
    void backtrack(vector<int>& tmp, int n, int t, int& sum)
    {
        if(t == n)
            sum++;
        else
        {
            for(int i = 0; i < n; i++)
            {
                tmp[t] = i;
                if (isValid(tmp, t))
                    backtrack(tmp, n, t + 1, sum);
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

class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<int> cols(n, 1);
        vector<int> dia1(2 * n - 1, 1);
        vector<int> dia2(2 * n - 1, 1);
        backtrack(0, cols, dia1, dia2, n, cnt);
        return cnt;
    }
private:
    void backtrack(int row, vector<int> cols, vector<int> dia1, vector<int> dia2, int n, int& cnt)
    {
        if(row == n)
        {
            cnt++;
            return;
        }
        for(int col = 0; col < n; col++)
        {
            int id1 = row + col, id2 = n - 1 + col - row;
            if(cols[col] && dia1[id1] && dia2[id2])
            {
                cols[col] = dia1[id1] = dia2[id2] = 0;
                backtrack(row + 1, cols, dia1, dia2, n, cnt);
                cols[col] = dia1[id1] = dia2[id2] = 1;
            }   
        }
    }
};