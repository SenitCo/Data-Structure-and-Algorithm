/*@Description: Text Justification
Given an array of words and a length L, format the text such that each line has exactly L characters 
and is fully (left and right) justified. You should pack your words in a greedy approach; that is, 
pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has 
exactly L characters. Extra spaces between words should be distributed as evenly as possible. If the 
number of spaces on a line do not divide evenly between words, the empty slots on the left will be 
assigned more spaces than the slots on the right. For the last line of text, it should be left justified 
and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.
Return the formatted lines as:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Note: Each word is guaranteed not to exceed L in length.
Corner Cases:
A line other than the last line might contain only one word. What should you do in this case?
In this case, that line should be left-justified.
*/


class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        int i = 0, k = 0, l = 0;
        for(i = 0; i < words.size(); i += k) 
        {
            for(k = l = 0; i + k < words.size() && l + words[i + k].size() <= L - k; k++) 
            {
                l += words[i+k].size();
            }
            string tmp = words[i];
            for(int j = 0; j < k - 1; j++) 
            {
                if(i + k >= words.size()) 
                    tmp += " ";
                else 
                    tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
                tmp += words[i + j + 1];
            }
            tmp += string(L - tmp.size(), ' ');
            res.push_back(tmp);
        }
        return res;
    }
};