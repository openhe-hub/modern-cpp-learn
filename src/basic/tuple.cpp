#include <iostream>
#include <string>
#include <tuple>

// 使用tuple进行多返回值打包，auto解包

std::tuple<int, double, std::string> foo() {
  return std::make_tuple(1, 2.3, "xxx");
}

int main(int argc, char **argv) {
  auto [x, y, z] = foo();
  std::cout << x << "," << y << "," << z << std::endl;
  return 0;
}