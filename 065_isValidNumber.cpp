/*@Description: Valid Number
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements 
up front before implementing one.
*/

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        for(; s[i] == ' '; i++) {}  // skip the whilespaces

        if(s[i] == '+' || s[i] == '-') i++;     // check the significand, skip the sign if exist

        int n_num = 0, n_point = 0;
        for(; (s[i] >= '0' && s[i] <='9') || s[i]=='.'; i++)
            s[i] == '.' ? n_point++ : n_num++;       
        if(n_point > 1 || n_num < 1) // no more than one point, at least one digit
            return false;

        // check the exponent if exist
        if(s[i] == 'e') {
            i++;
            if(s[i] == '+' || s[i] == '-') i++;     // skip the sign

            n_num = 0;
            for(; s[i] >= '0' && s[i] <='9'; i++, n_num++) {}
            if(n_num < 1)
                return false;
        }

        for(; s[i] == ' '; i++) {}  // skip the trailing whitespaces

        return i == s.length();  // must reach the ending 0 of the string
    }
};