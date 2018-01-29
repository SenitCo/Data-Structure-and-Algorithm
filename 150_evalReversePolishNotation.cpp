/**@Description: Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

/**
从左往右依次遍历表达式中的每个数字和符号，遇到数字就进栈，遇到符号就将栈顶的两个数字出栈，
进行运算（注意运算顺序），运算结果进栈，直到获得最终结果
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for (int i = 0; i < tokens.size(); i++)
        {
            char c = tokens[i][0];	//此处条件判断可直接用字符串比较（tokens[i] == "+"）
            if (tokens[i].size() == 1 && (c < '0' || c > '9'))	
            {
                int a = num.top();
                num.pop();
                int b = num.top();
                num.pop();
                switch (c)
                {
                case '+':
                    num.push(b + a);
                    break;
                case '-':
                    num.push(b - a);
                    break;
                case '*':
                    num.push(b * a);
                    break;
                case '/':
                    num.push(b / a);
                    break;
                }
            }
            else
                num.push(std::stoi(tokens[i]));
        }
        return num.top();
    }
};