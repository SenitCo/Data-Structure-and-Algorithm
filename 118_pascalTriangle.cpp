/*@Description: Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5, Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        for(int i = 0; i < numRows; i++)
        {
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i][i] = 1;
            for(int j = 1; j < i; j++)
                triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        return triangle;
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows, vector<int>());
        if(numRows == 0)    return triangle;
        triangle[0].push_back(1);
        for(int i = 1; i < numRows; i++)
        {
            triangle[i].push_back(1);
            for(int j = 1; j < i; j++)
            {
                triangle[i].push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);   
            }
            triangle[i].push_back(1);
        }
        return triangle;
    }
};