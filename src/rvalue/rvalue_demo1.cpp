#include <algorithm>
#include <iostream>
#include <string>

// lvalue: 左值，表达式完成后依然存在的持久对象
// rvalue: 右值，表达式完成后不存在的临时对象
// prvalue: 纯右值，字面量除字符串（字符串为左值对象）
// xvalue: 将亡值，即将被销毁，但是可以被移动

void reference(std::string &str) { std::cout << "lvalue" << std::endl; }

void reference(std::string &&str) { std::cout << "rvalue" << std::endl; }

int main(int argc, char **argv) {
  std::string str1 = "string";
  reference(str1); // lvalue
  std::string&& str1_cp = std::move(str1);
  reference(std::move(str1)); //rvalue
  reference(str1_cp); // lvalue
  return 0;
}