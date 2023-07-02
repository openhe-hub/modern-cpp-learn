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

// 解包参数demo2

// if constexpr 编译期条件语句

// cpp17
template <typename T, typename... Ts> void print2(T value, Ts... args) {
  std::cout << value << std::endl;
  std::cout << "size = " << sizeof...(args) << std::endl;
  if constexpr (sizeof...(args) > 0) print2(args...);
}

int main(int argc, char **argv) {
  print2(1, 2.3, "1212", 1231212L);
  return 0;
}