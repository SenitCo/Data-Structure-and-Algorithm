/*@Description: Word Ladder
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest 
transformation sequence from beginWord to endWord, such that:
Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

For example, Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log","cog"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
*/

//广度优先遍历：对于求取最小长度(深度)，一般采用广度优先遍历
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int size = wordList.size();
        int depth = 2;
        vector<bool> visited(size, false);
        queue<string> toVisit;
        findNextWord(beginWord, wordList, toVisit, visited);
        while(!toVisit.empty())
        {
            int num = toVisit.size();   
            //此处的for循环是为了分层，统计层数(深度)，如果只是遍历所有元素，可不需要
            for(int i = 0; i < num; i++)
            {
                string word = toVisit.front();
                toVisit.pop();
                if(word == endWord)
                    return depth;
                findNextWord(word, wordList, toVisit, visited);
            }
            depth++;
        }
        return 0;
    }
private:
    void findNextWord(string& word, vector<string>& wordList, queue<string>& toVisit, vector<bool>& visited)
    {      
        for(int i = 0; i < wordList.size(); i++)
        {
            if(!visited[i] && numOfDiffLetter(word, wordList[i]) == 1)
            {
                toVisit.push(wordList[i]);
                visited[i] = true;
            }
        }
    }
        
    int numOfDiffLetter(string& word1, string& word2)
    {
        int cnt = 0;
        for(int i = 0; i < word1.size(); i++)
        {
            if(word1[i] != word2[i])
                cnt++;
        }
        return cnt;
    }
};

//深度优先遍历（递归调用），某些情况下会超时，不可取
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int size = wordList.size();
        int len = size + 1, depth = 0;
        vector<bool> visited(size, false);
        recursion(beginWord, endWord, wordList, visited, depth, len);
        if(len < size + 1)
            return len + 1;
        else
            return 0;
    }
private:
    void recursion(string& word, string& endWord, vector<string>& wordList, vector<bool>& visited, int depth, int& minLen)
    {
        if(numOfDiffLetter(word, endWord) == 0)
        {
            if(depth < minLen)
                minLen = depth;
            return;
        }
        for(int i = 0; i < wordList.size(); i++)
        {
            if(!visited[i] && numOfDiffLetter(word, wordList[i]) == 1)
            {
                visited[i] = true;
                recursion(wordList[i], endWord, wordList, visited, depth + 1, minLen);
                visited[i] = false;
            }
        }
    }
    int numOfDiffLetter(string& word1, string& word2)
    {
        int cnt = 0;
        for(int i = 0; i < word1.size(); i++)
        {
            if(word1[i] != word2[i])
                cnt++;
        }
        return cnt;
    }
};