#include <future>
#include <iostream>
#include <thread>
#include <utility>

// 使用std::future 等待并获取其他线程的执行结果

int main(int argc, char **argv) {
  std::packaged_task<int()> task([]() { return 10; });
  std::future<int> result = task.get_future();
  std::thread(std::move(task)).detach();
  result.wait();
  std::cout << "done ! result = " << result.get() << std::endl;
  return 0;
}