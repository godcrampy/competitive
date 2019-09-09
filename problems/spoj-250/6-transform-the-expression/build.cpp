#include <iostream>
#include <string>

using namespace std;

string rearangePair(string pairOfOps);
int positionOfMainOperator(string pairOfOps);

int main(int argc, char const *argv[])
{
    int iterations;
    cin >> iterations;
    for (int i = 0; i < iterations; i++)
    {
        string expression;
        cin >> expression;
        cout << rearangePair(expression) << '\n';
    }
    return 0;
}

string rearangePair(string expression)
{
    /*  
    (stuff*stuff) => stuffstuff*
    tested for:
    "((a+b)*(d+e))" => "((a+b)*(d+e))"
    */
    if (expression[0] == '(' && expression[expression.length() - 1] == ')')
    {
        int operatorPosition = positionOfMainOperator(expression);
        string pre = expression.substr(1, operatorPosition - 1);
        string post = expression.substr(operatorPosition + 1, expression.length() - 2 - operatorPosition);
        string op = {expression.at(operatorPosition)};
        pre = rearangePair(pre);
        post = rearangePair(post);
        return pre + post + op;
    }
    return expression;
}

int positionOfMainOperator(string expression)
{
    /*  
    (stuff1 * stuff2) => postion of *
    tested for 
    (a+b) => 2
    ((a+b)+(c+d)) =>6
    */
    // level is used to keep track of when the iterator enters an inner bracket
    // all the stuff inside the bracket should be treated as a single variable
    int level = 0;
    // iterator starts from one since the first char is '('
    for (int i = 1; i < expression.length(); i++)
    {
        if (expression.at(i) == '(')
            ++level;
        else if (expression.at(i) == ')')
            --level;
        if (!level)
            if (expression.at(i) == '+' || expression.at(i) == '-' || expression.at(i) == '*' || expression.at(i) == '/' || expression.at(i) == '^')
                return i;
    }
    return -1;
}