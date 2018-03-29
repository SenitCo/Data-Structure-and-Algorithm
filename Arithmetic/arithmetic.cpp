#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <unordered_map>
using namespace std;

#include "arithmetic.h"

string InfixToPostfix(string infix)
{
    string postfix;
    stack<char> mark;
    unordered_map<char, int> priority{ make_pair('+', 0), make_pair('-', 0), make_pair('*', 1), make_pair('/', 1), make_pair('~', 2)};
    char current;
    for (int i = 0; i < infix.size(); i++)
    {
        current = infix[i];
        if (isdigit(current))
        {
            postfix += current;
            //如果数字字符后面非运算符或者数字为最后一个元素，则在后缀表达式中添加一个空格，用于区分不同的实数
            if (i < infix.size() - 1 && !isdigit(infix[i + 1]) || i == infix.size() - 1)
                postfix += ' ';
        }
        else
        {
            switch (current)
            {
            case '(':
                mark.push(current);
                break;
            case ')':
                while (!mark.empty() && mark.top() != '(')
                {
                    postfix += mark.top();
                    mark.pop();
                }
                mark.pop();
                break;
            case '+':
            case '-':
                while (!mark.empty() && mark.top() != '(')
                {
                    postfix += mark.top();
                    mark.pop();
                }
                mark.push(current);
                break;
            case '*':
            case '/':
                while (!mark.empty() && priority[current] <= priority[mark.top()])
                {
                    postfix += mark.top();
                    mark.pop();
                }
                mark.push(current);
                break;
            }
        }
     
    }
    while (!mark.empty())
    {
        postfix += mark.top();
        mark.pop();
    }
    return postfix;
}

double caculate(string expression)
{
    double result = 0.0;
    stack<double> num;
    double left, right, temp;
    for (int i = 0; i < expression.size(); i++)
    {
        if (isdigit(expression[i]))
        {
            int currNum = atoi(&expression[i]); //仅截取数字字符串转换成整数，在后缀表达式中使用' '字符区分
            int k = currNum / 10;
            while (k > 0)   //跳过数字字符
            {
                k = k / 10;
                i++;
            }
            i++;    //跳过空格
            num.push(currNum);
        }
        else
        {
            right = num.top();
            num.pop();
            left = num.top();
            num.pop();
            switch (expression[i])
            {
            case '+':
                temp = left + right;
                break;
            case '-':
                temp = left - right;
                break;
            case '*':
                temp = left * right;
                break;
            case '/':
                temp = left / right;
                break;
            }
            num.push(temp);
        }
    }
    if (!num.empty())
        result = num.top();
    return result;
}