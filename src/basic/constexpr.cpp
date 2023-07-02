#include <iostream>
#include <ostream>
#define LEN 10

// 使用constexpr 编译期计算常量

constexpr int constexpr_length_foo() { return 10; }

constexpr int fibonacci(int n) {
  return n == 1 || n == 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
}

int main(int argc, char **argv) {
  char arr1[10];
  char arr2[LEN];

  constexpr int length = 1 + 2 + 3;
  char arr3[length];

  char arr4[constexpr_length_foo()];

  std::cout << fibonacci(10) << std::endl;

  return 0;
}