#include <iostream>
#include <thread>

struct MyFunctionObject {
    void operator()(int &x) const {
        x+=1;
        std::cout << "Reference version: " << x << std::endl;
    }

    void operator()(int *x) const {
        std::cout << "Pointer version: " << *x << std::endl;
        
    }

    void operator()(int x) const {
        std::cout << "Integer version: " << x << std::endl;
    }

    void operator()(double x) const {
        std::cout << "Double version: " << x << std::endl;
    }
};

void foo(int &x){
        x+=1;
        std::cout << "Reference version: " << x << std::endl;
}

int main() {

    // 1. 值传递
    int i = 42;
    double d = 3.14;
    MyFunctionObject myFuncObj;
    std::thread t1(myFuncObj, i);   // 调用整数版本
    std::thread t2(myFuncObj, d);   // 调用双精度浮点数版本
    t1.join();
    t2.join();

    // 2. 指针传递
    int *ptr = new int(10);
    std::thread t3(myFuncObj, ptr); // 调用指针版本
    t3.join();

    // 3. 引用传递
    int a = 20;
    // std::function<void(int &)> func = myFuncObj;
    // static_cast<void(*)(int &)>(myFuncObj);
    // std::thread t4(myFuncObj, std::ref(a));   // 调用引用版本，需要显示调用
    std::thread t4(foo, std::ref(a)); 
    std::cout << "ref:a=" << a << std::endl;
    t4.join();

    std::cout << " ----------- over -----------" << std::endl;
    return 0;
}

// // 线程传递参数
// // 1. 普通

// // void foo(int &x){
// //     x += 1;
// // }

// void foo(int x){
//     std::cout << "x:" << x << std::endl;
// }

// void foo(int *x){
//     *x = 1;
// }

// int main(int argc, char * argv[])
// {
//     // 1. 正常数据
//     int a = 1;
//     std::thread t1(foo(int x), a);
//     t1.join();

//     int * ptr = new int(10);
//     std::cout << "ptr: " << *ptr << std::endl;
//     std::thread t(foo, ptr);

//     delete ptr;    // 释放后
//     t.join();      // 地址资源被释放，无法修改
    
//     std::cout << "ptr: " << *ptr << std::endl;
//     std::cout << " ----------- over -----------" << std::endl;
//     return 0;
// }