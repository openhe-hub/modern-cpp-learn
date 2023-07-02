#include <iostream>
#include <ostream>
#include <string>

template <typename... Ts> auto sum(Ts... nums) {
  return (nums + ...); // fold expression
}

int main(int argc, char **argv) {
  auto ret = sum(1, 2, 3, 4);
  std::cout<< ret << std::endl;
  return 0;
}