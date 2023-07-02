#include <iostream>

// 可以将非类型作为模板参数传入

template <typename T, int buf_size> class Buffer {
public:
  T &alloc();
  void free(T &item);

private:
  T data[buf_size];
};

int main(int argc, char **argv) {
  auto buffer = new Buffer<int, 100>();
  return 0;
}