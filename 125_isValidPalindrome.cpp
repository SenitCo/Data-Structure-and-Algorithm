/*@Description: Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example, "A man, a plan, a canal: Panama" is a palindrome. "race a car" is not a palindrome.
Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if(len == 0)    return true;
        int i = 0, j = len - 1;
        for(; i < j; i++, j--)
        {
            char front, end;
            for(front = tolower(s[i]); i < j && !(front >= '0' && front <= '9') && !(front >= 'a' && front <= 'z'); front = tolower(s[++i])); 
            for(end = tolower(s[j]); i < j && !(end >= '0' && end <= '9') && !(end >= 'a' && end <= 'z'); end = tolower(s[--j]));
            if(front != end)
                break;
        }
        if(i < j)
            return false;
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) 
        { 
            while (isalnum(s[i]) == false && i < j) i++; 
            while (isalnum(s[j]) == false && i < j) j--; 
            if (toupper(s[i]) != toupper(s[j])) return false; 
        }  
        return true;
    }
};