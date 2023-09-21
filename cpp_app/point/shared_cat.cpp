#include <memory>
#include <iostream>
#include "cat.hpp"

int main(int argc, char * argv[])
{
    // 初始化
    std::shared_ptr<CAT> s_p1 = std::make_shared<CAT>("TTT");
    std::cout << "s_p1 value: "; s_p1->Display();  //std::cout << std::endl;
    std::cout << "use count:" << s_p1.use_count() << std::endl; 

    // copy
    std::shared_ptr<CAT> s_p2 = s_p1;
    std::cout << "s_p1 use count:" << s_p1.use_count() << std::endl; 
    std::cout << "s_p2 use count:" << s_p2.use_count() << std::endl; 

    // change value
    s_p1->SetName("Tom");
    std::cout << "s_p2 value: "; s_p2->Display();  //std::cout << std::endl;
    std::cout << "s_p1 value: "; s_p1->Display();  //std::cout << std::endl;
    // std::cout << "s_p1 value: " << s_p1->Display() << std::endl;

    // change point
    // s_p1 = nullptr;
    // std::cout << "s_p1 use count:" << s_p1.use_count() << std::endl; 
    // std::cout << "s_p2 use count:" << s_p2.use_count() << std::endl; 

    s_p1.reset();
    std::cout << "s_p1 use count:" << s_p1.use_count() << std::endl; 
    std::cout << "s_p2 use count:" << s_p2.use_count() << std::endl; 

    std::cout << "------- over --------" << std::endl;
    return 0;
}