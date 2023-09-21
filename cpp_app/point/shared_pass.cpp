#include <memory>
#include <iostream>

void pass(std::shared_ptr<int> sp)
{
    std::cout << "pass use count:" << sp.use_count() << std::endl; 
}

void pass_by_ref(std::shared_ptr<int> &sp)
{
    std::cout << "pass_by_ref use count:" << sp.use_count() << std::endl; 
}

std::shared_ptr<int> pass_return(std::shared_ptr<int> &sp)
{
    std::shared_ptr<int> rp = sp;
    // std::cout << "pass_return use count:" << sp.use_count() << std::endl; 
    return rp;
}

int main(int argc, char* argv[])
{
    std::shared_ptr<int> isp1 = std::make_shared<int>(10);
    std::cout << "value: " << *isp1 << std::endl;

    // 函数计数 +1 copy
    std::cout << "use count:" << isp1.use_count() << std::endl; 
    pass(isp1);
    std::cout << "use count:" << isp1.use_count() << std::endl; 

    // 引用传递
    pass_by_ref(isp1);
    std::cout << "use count:" << isp1.use_count() << std::endl; 

    // return
    std::shared_ptr<int> rp = pass_return(isp1);
    std::cout << "use count:" << rp.use_count() << std::endl; 
    
    std::cout << "------- over --------" << std::endl;
    return 0;
}