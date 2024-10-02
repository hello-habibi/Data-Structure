#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

stack<char> stk;

void push(char value)
{
    stk.push(value);
}
char pop()
{
    char ch = stk.top();
    stk.pop();
    return ch;
}
int precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    case '(':
    case ')':
    case '#':
        return 1;
    }
    return 0;
}

int isOperator(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case '(':
    case ')':
        return 1;
    default:
        return 0;
    }
}
void convert(string &inFix, string &postFix)
{
    int j = 0;
    stk.push('#');
    for (char symbol : inFix)
    {
        if (isOperator(symbol) == 0)
        {
            postFix += symbol;
            j++;
        }
        else
        {
            if (symbol == '(')
            {
                push('(');
            }
            else
            {
                if (symbol == ')')
                {
                    while (stk.top() != '(')
                    {
                        postFix += pop();
                        j++;
                    }
                    stk.pop();
                }
                else
                {
                    if (precedence(symbol) > precedence(stk.top()))
                    {
                        push(symbol);
                    }
                    else
                    {
                        while (precedence(symbol) <= precedence(stk.top()))
                        {
                            postFix += pop();
                            j++;
                        }
                        push(symbol);
                    }
                }
            }
        }
    }
    while (stk.top() != '#')
    {
        postFix += pop();
        j++;
    }
    postFix[j] = '\0';
}
int evaluate(string &postFix)
{
    stack<int> stack_int;
    int operandOne, operandTwo;
    for (char ch : postFix)
    {
        if (isdigit(ch))
        {
            stack_int.push(ch - '0');
        }
        else
        {
            operandOne = stack_int.top();
            stack_int.pop();
            operandTwo = stack_int.top();
            stack_int.pop();
            switch (ch)
            {
            case '+':
                stack_int.push(operandOne + operandTwo);
                break;
            case '-':
                stack_int.push(operandOne - operandTwo);
                break;
            case '*':
                stack_int.push(operandOne * operandTwo);
                break;
            case '/':
                stack_int.push(operandOne / operandTwo);
                break;

            }
        }
    }
    return stack_int.top();
}

int main()
{
    string infix = "1*(2+3+3)^2", postfix;
    convert(infix, postfix);
    cout << "Infix expression is : " << infix << endl;
    cout << "PostFixExpression is : " << postfix << endl;
    cout<<"Evaluation of the expression is : " <<evaluate(postfix)<<endl;
}
