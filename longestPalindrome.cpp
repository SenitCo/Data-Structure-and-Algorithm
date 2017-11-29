/*@Description: Longest Palindromic Substring
	正读和反读都一样的字符串
*/

/*依次遍历字符串中每个字符，以该字符为起点，截取剩余长度子串，判断是否为回文序列，若不是，则子串长度递减，
直至不大于当前最长的回文序列；在外层循环中，若剩余长度不大于当前最长回文串的长度，则直接退出，时间复杂度O(N^2)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int startPos = 0, len = 0, maxLen = 0, end = 0;
        int lenS = s.size();
        for (int i = 0; i < lenS; i++)
        {
            len = lenS - i;    
            for (; len > maxLen; len--)
            {
                int j = 0;
                end = i + len / 2;
                for (j = i; j < end && s[j] == s[len + 2 * i - 1 - j]; j++);	//注意子串中取前后对应元素的下标
                if (j >= end && len > maxLen)
                {
                    maxLen = len;
                    startPos = i;
                    break;
                }
            } 
            if(len < maxLen)
                break;
        }
        return s.substr(startPos, maxLen);
    }
};

/*错误理解回文序列的做法，实现的功能为：找到最长的仅首尾字符相同的子串，如"abcdbca"->"bcdb"或者"cdbc"；
如序列中完全没有重复的字符就截取第一个字符，"abcdefg"->"a"
注释部分考虑了连续子串，如"abbbbc"->"bbbb"
思路：将字符串中所有元素按字符归类（一共256类），如果某个元素存在于字符串中，则在数组对应位置记录该元素
在字符串中的位置(array[s[i]] = i;)，并计算与前一个相同字符元素的距离，判断并记录当前最大的距离和前一个元素
的位置（子串起始位置）
*/
string longestPalindrome1(string s) {
    int startPos = -1, tmp = -1, len = 0, maxLen = 0;
    if (s.empty())
        return 0;
    if (s.size() == 1)
        return s;
    vector<int> array(256, -1);
    char ch = 0;
    for (int i = 0, j = 0; i < s.size(); i++)
    {
        if (array[s[i]] > -1)
        {
            len = i - array[s[i]];
            /*if (len == 1)
            {
                ch = s[i];
                while (ch == s[++i])
                    j++;
                i--;
            }
            len = len + j;*/

            if (len > maxLen)
            {
                startPos = array[s[i]];
                maxLen = len;
            }
        }
        array[s[i]] = i;
        j = 0;
    }
    if (startPos == -1)
        startPos = 0;
    string sub = s.substr(startPos, maxLen + 1);
    return sub;
}

/*reference
依次遍历字符串中的元素，并以该元素为中心点向两边搜索，判断两边元素是否对称，并延伸至最大长度，
而且在中心点处考虑了重复元素（连续出现）的情况
*/
string longestPalindrome(string s) 
{
    if (s.empty()) 
    	return "";
    if (s.size() == 1) 
    	return s;
    int min_start = 0, max_len = 1;
    for (int i = 0; i < s.size();) 
    {
     	if (s.size() - i <= max_len / 2) 	
      		break;
	    int j = i, k = i;
	    while (k < s.size()-1 && s[k+1] == s[k]) 	// Skip duplicate characters.
	    	++k; 
	    i = k + 1;
	    while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) 	// Expand.
	    { 
	    	++k; 
	    	--j; 
	    }
	    int new_len = k - j + 1;
	    if (new_len > max_len)
	    { 
	    	min_start = j; 
	    	max_len = new_len; 
	    }
    }
    return s.substr(min_start, max_len);
}