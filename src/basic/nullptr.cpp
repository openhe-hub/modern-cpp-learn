#include <cstddef>
#include <iostream>
#include <type_traits>

// 传统的null可能会是0或者(void*)0，使用nullptr统一空指针问题

void foo(char *) { std::cout << "foo(char*) is called" << std::endl; }
void foo(int i) { std::cout << "foo(int) is called" << std::endl; }

int main(int argc, char **argv) {
  if (std::is_same<decltype(NULL), decltype(0)>::value) {
    std::cout << "NULL = 0 " << std::endl;
  }

  if (std::is_same<decltype(NULL), decltype((void *)0)>::value) {
    std::cout << "NULL = (void*)0 " << std::endl;
  }

  if (std::is_same<decltype(NULL), decltype(nullptr)>::value) {
    std::cout << "NULL = nullptr " << std::endl;
  }

//   foo(NULL); error!

  foo(0);
  foo(nullptr);

  return 0;
}