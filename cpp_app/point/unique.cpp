#include <memory>
#include <iostream>
#include <string>
#include "cat.hpp"

// 1. 基本的情况
// int main(int argc, char *argv[])
// {
//     CAT c("Tom");
//     c.Display();
//     {   // 局部作用域
//         CAT c("Mini");
//         c.Display();
//     }
//     std::cout <<  "------ over -----" << std::endl;
//     return 0;
// }
/*
 Constructor of Cat : Tom
 CAT name: Tom
 Constructor of Cat : Mini
 CAT name: Mini
 Destructor of Cat : Mini
------ over -----
 Destructor of Cat : Tom
*/


// 2. 原始指针 (不会释放) 在 heap 上的内存
// int main(int argc, char *argv[])
// {
    
//     CAT *ptr = new CAT("Tom");
//     ptr->Display();

//     {   // 局部作用域
//         CAT *ptr = new CAT("Mini");
//         ptr->Display();
//     }
//     std::cout <<  "------ over -----" << std::endl;
//     return 0;
// }
/*
 Constructor of Cat : Tom
 CAT name: Tom
 Constructor of Cat : Mini
 CAT name: Mini
------ over -----
*/


// 3. 原始指针 (不会释放) 在 heap 上的内存  delete会调用析构函数
// int main(int argc, char *argv[])
// {
    
//     CAT *ptr = new CAT("Tom");
//     ptr->Display();

//     {   // 局部作用域
//         CAT *ptr = new CAT("Mini");
//         ptr->Display();
//         delete ptr;
//     }
//     delete ptr;   // 析构函数在前
//     std::cout <<  "------ over -----" << std::endl;
//     return 0;
// }
/*
 Constructor of Cat : Tom
 CAT name: Tom
 Constructor of Cat : Mini
 CAT name: Mini
 Destructor of Cat : Mini
 Destructor of Cat : Tom
------ over -----
*/


// 4. 指针重复释放 (常见错误)
// int main(int argc, char *argv[])
// {
    
//     CAT *ptr = new CAT("Tom");
//     ptr->Display();

//     {   // 局部作用域
//         ptr = new CAT("Mini");    //  对指针赋值，原来的地址丢失，使得内存泄漏
//         ptr->Display();
//         delete ptr;               // 释放一次
//     }
//     delete ptr;                   // 第二次释放
//     std::cout <<  "------ over -----" << std::endl;
//     return 0;
// }
/*
 Constructor of Cat : Tom
 CAT name: Tom
 Constructor of Cat : Mini
 CAT name: Mini
 Destructor of Cat : Mini
 Destructor of Cat : 
main(78640,0x7ff848dbd640) malloc: Double free of object 0x7feb56f05d30
main(78640,0x7ff848dbd640) malloc: *** set a breakpoint in malloc_error_break to debug
[1]    78640 abort      ./main
*/


// 5. 独占指针 unique_ptr  创建, 解引用
// int main(int argc, char *argv[])
// {
//     // 1.
//     CAT *ptr = new CAT("Tom");
//     std::unique_ptr<CAT> u_p1(ptr); // 需要独占，
    
//     // ptr->Display();                      // ptr仍可用
//     // u_p1->Display();
//     // ptr->SetName("TToomm");
//     // ptr->Display();
//     // u_p1->Display();
//     ptr = nullptr;

//     // 2. new
//     std::unique_ptr<CAT> u_p2(new CAT("Tom2"));
//     u_p2->SetName("Tt");

//     // 3. make_unique<>()   
//     std::unique_ptr<CAT> u_p3 = std::make_unique<CAT>("make");  //std c++ 14
//     u_p3->Display();

//     // 地址, 引用
//     std::unique_ptr<int> u_i_p(new int(100));
//     std::cout << "int address:" <<  u_i_p.get() << std::endl;
//     std::cout << "CAT address:" <<  u_p2.get() << std::endl;

//     // std::cout << *u_p2 << std::endl;   // 需要重载
//     std::cout << *u_i_p << std::endl;

//     std::cout <<  " ------ over ----- " << std::endl;
//     return 0;
// }