/*@Description: Spiral Matrix II
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example, Given n = 3, You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/**
和Spiral Matrix解法一致，依次往四个方向遍历，并向矩阵中填入对应元素
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        vector<vector<int>> dirs({{0, 1}, {1, 0}, {0, -1}, {-1, 0}});   //表示遍历方向
        int num = n * n + 1;
        vector<int> step({n, n - 1});   //横纵方向遍历的步长（依次递减）
        int ir = 0, ic = -1, idx = 0;
        for(int i = 1; i < num;)
        {
            for(int j = 0; j < step[idx % 2]; j++)
            {
                ir += dirs[idx][0];
                ic += dirs[idx][1];
                result[ir][ic] = i;
                i++;
            }
            step[idx % 2]--;
            idx = (idx + 1) % 4;
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1, num = 1;
        
        //通过横纵边界作为循环条件
        while (rowStart <= rowEnd && colStart <= colEnd) {  
            for (int j = colStart; j <= colEnd; j++) {
                matrix[rowStart][j] = num++; 
            }
            rowStart++;
            
            for (int i = rowStart; i <= rowEnd; i++) {
                matrix[i][colEnd] = num++; 
            }
            colEnd--;
            
            if (rowStart <= rowEnd) {
                for (int j = colEnd; j >= colStart; j--) {
                        matrix[rowEnd][j] = num++; 
                }
                rowEnd--;
            }
            
            if (colStart <= colEnd) {
                for (int i = rowEnd; i >= rowStart; i--) {
                        matrix[i][colStart] = num++; 
                }
                colStart ++;
            }
        }
        
        return matrix;
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int rowStart = 0, rowEnd = n - 1, colStart = 0, colEnd = n - 1, num = 1;
        //元素总数作为循环条件
        while (num < n * n + 1) {
            for (int j = colStart; j <= colEnd; j++) {
                matrix[rowStart][j] = num++; 
            }
            rowStart++;
            
            for (int i = rowStart; i <= rowEnd; i++) {
                matrix[i][colEnd] = num++; 
            }
            colEnd--;
            
            for (int j = colEnd; j >= colStart; j--) {
                    matrix[rowEnd][j] = num++; 
            }
            rowEnd--;

            for (int i = rowEnd; i >= rowStart; i--) {
                    matrix[i][colStart] = num++; 
            }
            colStart++;
        }
        
        return matrix;
    }
};

