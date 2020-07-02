#include <iostream>
#include <stack>

class MaxStack {
 private:
  std::stack<int> main_stack;
  std::stack<int> aux_stack;

 public:
  void pop() {
    if (this->main_stack.top() == this->aux_stack.top()) this->aux_stack.pop();
    this->main_stack.pop();
  }
  void push(int number) {
    this->main_stack.push(number);
    if (this->aux_stack.empty() || number >= this->aux_stack.top())
      this->aux_stack.push(number);
  }
  int max() { return aux_stack.top(); }
};

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  MaxStack stack;
  for (int i = 0; i < n; ++i) {
    std::string command;
    std::cin >> command;
    if (command == "max")
      std::cout << stack.max() << std::endl;
    else {
      if (command == "push") {
        int n;
        std::cin >> n;
        stack.push(n);
      } else
        stack.pop();
    }
  }
  return 0;
}
