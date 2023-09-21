#include <string>
#include <thread>
#include <iostream>

void foo(int & x){
    x+=1;
    return;
}

int main()
{
    int a = 1;                                        // 主函数局部变量
    std::thread t1(foo, std::ref(a));                 // a 作为引用传递给线程
   
    t1.join();

    std::cout << "a after thread: " << a << std::endl; // 输出修改后的 a
    return 0;
}