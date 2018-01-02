/*@Description: Plus One
Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
You may assume the integer do not contain any leading zero, except the number 0 itself.
The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int step = 1, temp = 0;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            temp = digits[i];
            digits[i] = (temp + step) % 10;
            step = (temp + step) / 10;
        }
        if(step > 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};