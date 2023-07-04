#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

int main(int argc, char **argv) {
  std::queue<int> product_queue;
  std::mutex mtx;
  std::condition_variable cv;
  bool notified = false;

  auto producer = [&]() {
    for (int i = 0;; i++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(900));
      std::unique_lock<std::mutex> lck(mtx);
      std::cout << "producing" << std::endl;
      product_queue.push(i);
      notified = true;
      cv.notify_all();
    }
  };

  auto consumer = [&]() {
    while (true) {
      std::unique_lock<std::mutex> lck(mtx);
      while (!notified) {
        cv.wait(lck);
      }

      lck.unlock();
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      lck.lock();
      while (!product_queue.empty()) {
        std::cout << "consuming" << std::endl;
        std::cout << product_queue.front() << std::endl;
        product_queue.pop();
      }
      notified = false;
    };
  };

  std::thread p(producer);
  std::thread c(consumer);
  p.join();
  c.join();

  return 0;
}