#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

int a = 1;
std::mutex mtx;

void func(int &x)
{
    for(int i=0; i<10000; i++)
    {
        mtx.lock();   // 后面没解锁，其他线程无法访问  x
        x++;          // 防止数据竞争
        mtx.unlock(); 
    }
}

int main()
{
    std::thread t1(func, std::ref(a));
    std::thread t2(func, std::ref(a));
    t1.join();
    t2.join();

    std::cout << a << std::endl;

    std::cout << "---------- over -----------" << std::endl;
    return 0;
}