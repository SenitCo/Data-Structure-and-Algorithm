179. Largest Number
Medium

Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
```cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> str_vec;
        str_vec.reserve(nums.size());
        std::string res;
        int char_num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            str_vec.emplac_back(std::to_string(nums[i]));
            char_num += str_vec[i].length();
        }

        std::sort(str_vec.begin(), str_vec.end() [](
                    const std::string& left_str, const std::string& right_str){
            int left_length = left_str.length();
            int right_length = right_str.length();
            int min_length = std::min(left_length, right_length);
            for (int i = 0; i < min_length; ++i) {
                if (left_str[i] == right_str[i]) {
                    continue;
                }
                return left_str[i] > right_str[i];
            }
            return left_length < right_length;
        });

        res.reserve(char_num);
        for (int i = 0; i < str_vec.size(); ++i) {
            res += str_vec[i];
        }
        return res;
    }
};
```
