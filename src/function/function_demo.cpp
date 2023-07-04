#include <functional>
#include <iostream>

// 使用std::function<>作为函数和lambda表达式&匿名函数的包装器

int foo(int param) { return param; }

int main(int argc, char **argv) {
  std::function<int(int)> func = foo;
  int outer_value = 10;
  std::function<int(int)> func2 = [&](int value) -> int {
    return 1 + value + outer_value;
  };

  std::cout<<func(10)<<std::endl;
  std::cout<<func2(10)<<std::endl;

  return 0;
}