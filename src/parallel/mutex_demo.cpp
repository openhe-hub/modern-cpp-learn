#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void run_thread(int change_v){
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);
    // do competition operation
    v = change_v;
    std::cout<<v<<std::endl;
    // unlock
    lock.unlock();

    // do another competition operation
    lock.lock();
    v += 1;
    std::cout<<v<<std::endl;
}

int main(int argc, char** argv)
{
    std::thread t1(run_thread, 2), t2(run_thread, 3);
    t1.join();
    t2.join();
    return 0;
}