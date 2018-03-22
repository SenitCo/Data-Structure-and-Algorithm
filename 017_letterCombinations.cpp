/*@Description: Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string map[10] = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> letters;
        if(digits.empty())
            return letters;
        letters.push_back("");
        for(int i = 0; i < digits.length(); i++)
        {
            vector<string> temp;
            string chars = map[digits[i] - '0'];
            for(int j = 0; j < chars.length(); j++)
            {
                for(int k = 0; k < letters.size(); k++)
                {
                    temp.push_back(letters[k] + chars[j]);
                }
            }
            letters = temp;
        }
        return letters;
    }
};