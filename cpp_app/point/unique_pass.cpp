#include <iostream>
#include <memory>
#include "cat.hpp"
// using namespace std;

void pass_by_value(std::unique_ptr<CAT> c)  
{
    c->Display();
    c->SetName("TTOOMM");
    c->Display();
}

void pass_by_ref(std::unique_ptr<CAT> &c)   // 引用传递
{
    c->Display();
    c->SetName("TTOOMM");
    c->Display();
    // c.reset();
}

void pass_by_ref2(std::unique_ptr<CAT> const &c)   // 引用传递
{
    c->Display();
    c->SetName("TTOOMM");  // 不能更改数据
    c->Display();
    // c.reset();
}

std::unique_ptr<CAT> unique_return()   // 引用传递
{
    std::unique_ptr<CAT> c = std::make_unique<CAT>("local cat");
    // c->Display();
    // c->SetName("TTOOMM");  // 不能更改数据
    // c->Display();
    // c.reset();
    return c;
}


// 数据传递
int main(int argc, char* argv[]){
    

    // 1. 值传递，
    std::unique_ptr<CAT> c1 = std::make_unique<CAT>("Tom");
    // pass_by_value(c1);
    pass_by_value(std::move(c1));   // 拷贝构造函数，然后将(c1)资源给新的对象，c1就没有资源了。 函数结束时会析构掉，资源被释放，
    // pass_by_value(std::make_unique<CAT>());
    // c1->Display();                  // c1 资源被释放，指针指向未定义数
    std::cout << "--- r ---" << std::endl;

    // 2. 引用传递
    std::unique_ptr<CAT> c2 = std::make_unique<CAT>("mimi");
    pass_by_ref(c2);
    c2->Display();  

    // std::cout << "--- r ---" << std::endl;
    // std::unique_ptr<CAT> const c3 = std::make_unique<CAT>("mimi");
    // pass_by_ref2(c3);
    // c2->Display();  

    // unique_ptr<CAT> c2 = make_unique<CAT>(c1);
    // c2->Display();
    // pass_by_ref(c1);
    
    // 3. return
    unique_return()->Display();
    std::cout << "------- over --------" << std::endl;
}