#include <iostream>
#include <memory>
#include <thread>
#include <mutex>

int a = 1;
int b = 2;
std::mutex mtx1;
std::mutex mtx2;

void func_1()
{
    std::cout << "------- func_1 begin -------" << std::endl;
    for(int i=0; i<500; i++)
    {
        mtx1.lock();
        mtx2.lock();

        mtx1.unlock(); 
        mtx2.unlock();
    }
    std::cout << "------- func_1 over -------" << std::endl;
}

void func_2()
{
    std::cout << "------- func_2 begin -------" << std::endl;
    for(int i=0; i<500; i++)
    {
        mtx2.lock();
        mtx1.lock();

        mtx2.unlock(); 
        mtx1.unlock();
    }
    std::cout << "------- func_2 over -------" << std::endl;
}


int main()
{
    std::thread t1(func_1);
    std::thread t2(func_2);
    t1.join();
    t2.join();

    std::cout << a << std::endl;

    std::cout << "---------- over -----------" << std::endl;
    return 0;
}