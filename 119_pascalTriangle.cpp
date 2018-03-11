/*@Description: Pascal's Triangle II
Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3, Return [1,3,3,1].
Note: Could you optimize your algorithm to use only O(k) extra space?
*/

/**
迭代公式为result[j] = result[j] + result[j - 1]，在遍历时需从后往前进行，避免前面的值在更新时被覆盖
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 0);
        result[0] = 1;
        for(int i = 1; i < rowIndex + 1; i++)
        {
            for(int j = i; j > 0; j--)
                result[j] += result[j - 1];
        }
        return result;
    }
};