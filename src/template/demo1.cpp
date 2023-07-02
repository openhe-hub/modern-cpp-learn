#include <iostream>
#include <ostream>
#include <string>

// 可变参数长度的模板
// template<typename... Ts>

// 可变参数长度+手动定义
// template<typename Require, typename... Args>

// 可变参数长度+类型限制 => 类型安全
// template<typename... Args>
// void my_printf(const std::string& str, Args... args)

// 获取参数长度
// sizeof...(args)

// 解包参数demo1

template <typename T0> void print1(T0 value) {
  std::cout << value << std::endl;
}

template <typename T, typename... Ts> void print1(T value, Ts... args) {
  std::cout << value << std::endl;
  std::cout << "size = " << sizeof...(args) << std::endl;
  print1(args...);
}

int main(int argc, char **argv) {
  print1(1, 2.3, "1212", 1231212L);
  return 0;
}