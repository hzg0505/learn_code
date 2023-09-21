#include <memory>
#include <iostream>

int main(int argc, char * argv[])
{
    // 初始化
    std::shared_ptr<int> i_s_p1 = std::make_shared<int>(10);
    std::cout << "value: " << *i_s_p1 << std::endl;
    std::cout << "use count:" << i_s_p1.use_count() << std::endl; 

    // copy
    std::shared_ptr<int> i_s_p2 = i_s_p1;
    std::cout << "i_s_p1 use count:" << i_s_p1.use_count() << std::endl; 
    std::cout << "i_s_p2 use count:" << i_s_p2.use_count() << std::endl; 

    // change value
    *i_s_p1 = 20;
    std::cout << "i_s_p2 value: " << *i_s_p2 << std::endl;
    std::cout << "i_s_p1 value: " << *i_s_p1 << std::endl;

    // change point
    // i_s_p2 = nullptr;
    // std::cout << "i_s_p1 use count:" << i_s_p1.use_count() << std::endl; 
    // std::cout << "i_s_p2 use count:" << i_s_p2.use_count() << std::endl; 

    i_s_p1 = nullptr;
    std::cout << "i_s_p1 use count:" << i_s_p1.use_count() << std::endl; 
    std::cout << "i_s_p2 use count:" << i_s_p2.use_count() << std::endl; 

}