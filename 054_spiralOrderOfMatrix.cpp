/*@Description: Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example, Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/


/**
向右遍历，向下遍历，向左遍历，向上遍历，循环往复，每次遍历结束，修改边界条件；在向左、向上遍历的时候
需要重新判断一次边界条件，因为在前两次遍历过程中，边界条件已被修改
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty())
            return result;
        int rowBegin = 0, rowEnd = matrix.size() - 1, colBegin = 0, colEnd = matrix[0].size() - 1;
        while(rowBegin <= rowEnd && colBegin <= colEnd)
        {
            for(int j = colBegin; j <= colEnd; j++)
                result.push_back(matrix[rowBegin][j]);
            rowBegin++;
            for(int i = rowBegin; i <= rowEnd; i++)
                result.push_back(matrix[i][colEnd]);
            colEnd--;
            if(rowBegin <= rowEnd)      //重新判断条件
            {
                for(int j = colEnd; j >= colBegin; j--)
                    result.push_back(matrix[rowEnd][j]);
            }
            rowEnd--;
            if(colBegin <= colEnd)
            {
                for(int i = rowEnd; i >= rowBegin; i--)
                    result.push_back(matrix[i][colBegin]);
            }
            colBegin++;
        }
        return result;
    }
};

/**
When traversing the matrix in the spiral order, at any time we follow one out of the following four directions: 
RIGHT DOWN LEFT UP. Suppose we are working on a 5 x 3 matrix as such:

0 1 2 3 4 5
6 7 8 9 10
11 12 13 14 15

Imagine a cursor starts off at (0, -1), i.e. the position at ‘0’, then we can achieve the spiral order by doing
the following:

Go right 5 times
Go down 2 times
Go left 4 times
Go up 1 times.
Go right 3 times
Go down 0 times -> quit

Notice that the directions we choose always follow the order ‘right->down->left->up’, and for horizontal movements, 
the number of shifts follows:{5, 4, 3}, and vertical movements follows {2, 1, 0}. Thus, we can make use of a direction 
matrix that records the offset for all directions, then an array of two elements that stores the number of shifts for 
horizontal and vertical movements, respectively. This way, we really just need one for loop instead of four.

Another good thing about this implementation is that: If later we decided to do spiral traversal on a different direction 
(e.g. Counterclockwise), then we only need to change the Direction matrix; the main loop does not need to be touched.

通过定义四组方向参数，以及每次遍历时迭代的次数，将四次遍历统一起来（无需写四组循环）

*/
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    vector<vector<int>> dirs{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };   //方向参数，依次为向左、向下、向右、向上
    vector<int> res;
    int nr = matrix.size();     if (nr == 0) return res;
    int nc = matrix[0].size();  if (nc == 0) return res;

    vector<int> nSteps{nc, nr - 1};     //每次横纵遍历迭代的次数

    int iDir = 0;   // index of direction.
    int ir = 0, ic = -1;    // initial position
    while (nSteps[iDir % 2]) {
        for (int i = 0; i < nSteps[iDir % 2]; ++i) {
            ir += dirs[iDir][0]; 
            ic += dirs[iDir][1];
            res.push_back(matrix[ir][ic]);
        }
        nSteps[iDir % 2]--;     //迭代次数依次递减
        iDir = (iDir + 1) % 4;
    }
    return res;
}

/*和方法一相同*/
vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    if (matrix.empty()) return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> spiral(m * n);
    int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
    while (true) {    
        for (int col = l; col <= r; col++)  spiral[k++] = matrix[u][col];    // up
        if (++u > d) break;

        for (int row = u; row <= d; row++)  spiral[k++] = matrix[row][r];    // right
        if (--r < l) break;
        
        for (int col = r; col >= l; col--)  spiral[k++] = matrix[d][col];    // down
        if (--d < u) break;
        
        for (int row = d; row >= u; row--)  spiral[k++] = matrix[row][l];    // left
        if (++l > r) break;
    }
    return spiral;
}