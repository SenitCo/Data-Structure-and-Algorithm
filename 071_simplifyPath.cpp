/*@Description：Simplify Path
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

class Solution {
public:
    string simplifyPath(string path) {
        string result, temp;
        vector<string> vs;
        stringstream ss(path);
        while(getline(ss, temp, '/'))	//getlines可以分割(split)字符串
        {
            if(temp == "" || temp == ".")
                continue;
            if(temp == "..")
            {
                if(!vs.empty())
                    vs.pop_back();
            }
            else
                vs.push_back(temp);
        }
        for(auto s : vs)
            result += '/' + s;
        return result.empty() ? "/" : result;
    }
};