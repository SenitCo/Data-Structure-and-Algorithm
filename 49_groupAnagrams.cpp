/*@Description: Group Anagrams
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.
*/

/**
将每个字符串进行排序，并将排序后的字符串作为hash键值，对原始字符串进行索引分类
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        if(strs.size() == 0)
            return result;
        unordered_map<string, vector<string>> umap;
        for(string s : strs)
        {
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            if(umap.find(sortedStr) == umap.end())
            {
                umap.insert(make_pair(sortedStr, vector<string>(1, s)));
            }
            else
            {
                umap[sortedStr].push_back(s);
            }
        }
        for(auto m = umap.begin(); m != umap.end(); m++)
        {
            result.push_back(m->second);
        }
        return result;
    }
};


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> umap;
        for (string s : strs) 
        {
            string t = s; 
            sort(t.begin(), t.end());
            umap[t].push_back(s);
        }
      
        for (auto m = umap.begin(); m != umap.end(); m++) 
            result.push_back(m->second);
        return result;
    }
};