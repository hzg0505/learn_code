#include <iostream>
#include <thread>
#include <string>
// #include <functional>

void printHelloWorld(std::string msg)
{
    std::cout << msg << std::endl;
    return;
}


int main()
{
    // 1. create thread
    std::thread t1(printHelloWorld, "Hello, world!");   // 参数传递

    // 2. join  // 主程序检查子线程是否执行完毕
    // t1.join();

    // 3. detach()

    // 4, joinable
    bool isJoin = t1.joinable();

    if(isJoin)
    {
        t1.join();
    }

    std::cout << "---------- over -----------" << std::endl;
    return 0; 
}
