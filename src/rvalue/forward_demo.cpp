#include <algorithm>
#include <iostream>
#include <utility>

// 引用坍缩， 当创建引用的引用
// 当T为左值引用时，T&和T&&都将坍缩为T&
// 当T为右值引用或非引用时，T&保持为T&，T&&保持为T&&

// 完美转发， 传递参数时保持引用类型，左引用保持左引用，右引用保持右引用

void reference(int &v) { std::cout << "lvalue" << std::endl; }

void reference(int &&v) { std::cout << "rvalue" << std::endl; }

template <typename T> void pass(T &&v) {
  std::cout << "common forward" << std::endl;
  reference(v); //将右值1绑定在右值v上，会导致v成为左值
  std::cout << "move forward" << std::endl;
  reference(std::move(v));
  std::cout << "forward forward" << std::endl;
  reference(std::forward<T>(v));
  std::cout << "static cast forward" << std::endl;
  reference(static_cast<T &&>(v));
}

int main(int argc, char **argv) {
  std::cout << "passing right value" << std::endl;
  pass(1);

  std::cout << "passing left value" << std::endl;
  int v = 1;
  pass(v);

  return 0;
}