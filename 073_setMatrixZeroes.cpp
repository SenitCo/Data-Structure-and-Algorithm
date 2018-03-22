/*@Description: Set Matrix Zeroes
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

/**
定义两个数组分别记录含有0元素的行列，然后进行置零操作
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++)
        {
            if(rows[i] == 1) 
                memset(&matrix[i][0], 0, n * sizeof(int));
        }
        
        for(int j = 0; j < n; j++)
        {
            if(cols[j] == 1)
            {
                for(int i = 0; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
    }
};

/**
在记录为0的行列时，顺带将对应行置零
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> rows(m, 0), cols(n, 0);
        for(int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
            if (rows[i])
                memset(&matrix[i][0], 0, n * sizeof(int));
        }
        
        for(int j = 0; j < n; j++)
        {
            if(cols[j] == 1)
            {
                for(int i = 0; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
    }
};

/**
用matirx[i][0]记录第 i 行含0的情况，matrix[0][j]记录第 j 列含0的情况，由于记录首行首列的坐标均为
matrix[0][0]导致重复，因此单独定义一个变量记录首列为0的情况
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < cols; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 1; j--)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if (col0 == 0) matrix[i][0] = 0;
        }
    }
};