#include <iostream>
#include <memory>
#include <string>
#include <thread>

class A
{
friend void thread_foo();
private:
    // int a;
    void foo(){
        std::cout << "Hello "  << std::endl;
    }

};

void thread_foo(){
    std::shared_ptr<A> a = std::make_unique<A>(new A());
    std::thread t(&A::foo, a);
    t.join();
}


int main(){
    thread_foo();
    std::cout << "--------- over ----------" << std::endl;
    return 0;
}