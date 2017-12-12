
/*@Description: ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
 (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
也就是将字符串按之字形排列，然后逐行读取
*/

/* 字符以“之”字形出现的周期为 (T=2*n-2)，n为总行数，对于每一行，先读取往下走的字符，然后读取斜向上走的字符，
且两个字符之间的距离为 (T-2*i)，i为行数
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        string result;
        if(s.empty())
            return result;
        int period = numRows + numRows - 2;
        int length = s.length();
        
        for(int i = 0; i < numRows; i++ )
        {
            for(int j = i; j < length; j += period)
            {                    
                result.append(1, s[j]);
                if(i != 0 && i != numRows - 1 && j + period - 2 * i < length)
                {
                    result.append(1, s[j + period - 2 * i]);
                }
            }
        }
        return result;
    }
};