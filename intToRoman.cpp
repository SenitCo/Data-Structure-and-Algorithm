/*@Description: Integer to Roman
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
*/

/*
I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;

其中每两个阶段的之间有一个减法的表示，比如900=CM， C写在M前面表示M-C。
*/
class Solution1 {
public:
    string intToRoman(int num) {
        string result;    
        string symbol[] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };    
        int value[] = {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1};   
        for(int i = 0; num != 0; ++i)  
        {  
            while(num >= value[i])  
            {  
                num -= value[i];  
                result += symbol[i];  
            }  
        }  
        return result;  
    }  
};


/*
1~9: {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
10~90: {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
100~900: {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
1000~3000: {"M", "MM", "MMM"}.
*/
class Solution2 {
public:
    string intToRoman(int num) {
        string roman[4][10] = {  
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  
            {"", "M", "MM", "MMM"}  
        };  
          
        string result = "";  
        int digit = 0;  
        while (num != 0) {  
            int remain = num % 10;  
            result = roman[digit][remain] + result;  
            digit++;  
            num /= 10;  
        }  
          
        return result; 
    }
};