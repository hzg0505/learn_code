#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(42);
    std::shared_ptr<int> sharedPtr = std::move(uniquePtr); // 通过 std::move 转换
    
    if (!uniquePtr) {
        std::cout << "uniquePtr is empty" << std::endl;
    }

    std::cout << "sharedPtr use_count: " << sharedPtr.use_count() << std::endl;

    std::cout << " -------- over -----------" << std::endl;
    return 0;
}
