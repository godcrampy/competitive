#include <iostream>
#include <string>
#include <stack>

bool is_opening_bracket(char charecter)
{
  return charecter == '(' | charecter == '[' | charecter == '{' ? true : false;
}

bool is_closing_bracket(char charecter)
{
  return charecter == ')' | charecter == ']' | charecter == '}' ? true : false;
}

bool are_pairs(char opening, char closing)
{
  if (opening == '(' && closing == ')')
    return true;
  if (opening == '[' && closing == ']')
    return true;
  if (opening == '{' && closing == '}')
    return true;
  return false;
}

int find_first_unmatched_bracket(std::string &expression)
{
  std::stack<char> stack;
  std::stack<int> unsatisfied_openings;
  auto length_of_expression = expression.length();
  for (auto i = 0; i < length_of_expression; ++i)
  {
    if (is_opening_bracket(expression[i]))
    {
      stack.push(expression[i]);
      unsatisfied_openings.push(i);
    }
    if (is_closing_bracket(expression[i]))
      if (stack.empty())
        return i + 1;
      else if (are_pairs(stack.top(), expression[i]))
      {
        stack.pop();
        unsatisfied_openings.pop();
      }
      else
        // 1 indexed
        return i + 1;
  }
  if (!stack.empty())
    // 1 indexed
    return unsatisfied_openings.top() + 1;
  return -1;
}

int main(int argc, char const *argv[])
{
  std::string input;
  std::getline(std::cin, input);
  auto reply = find_first_unmatched_bracket(input);
  if (reply == -1)
    std::cout << "Success" << std::endl;
  else
    std::cout << reply << std::endl;
  return 0;
}
