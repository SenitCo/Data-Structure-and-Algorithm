/*@Description: Palindrome Number
Determine whether an integer is a palindrome. Do this without extra space
*/

class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> number;
        if(x < 0)
            return 0;
        while(x)
        {
            number.push_back(x % 10);
            x = x / 10;
        }
        int len = number.size();
        int i = 0;
        for(; i < len / 2 && number[i] == number[len - 1 - i]; i++);
        if(i < len / 2)
            return 0;
        return 1;
    }
};


//compare half of the digits in x, so don't need to deal with overflow.
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) 
            return false;
        int rev = 0;
        while (x > rev)
        {
            rev = rev * 10 + x % 10;
            x = x / 10;
        }
        return (x == rev || x == rev / 10);
    }
};