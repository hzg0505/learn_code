// 输入描述：
// 输入包括两个正整数a,b(1 <= a, b <= 10^9),输入数据有多组, 如果输入为0 0则结束输入
// 输出描述：
// 输出a+b的结果
// 示例1
// 输入例子：
// 1 5
// 10 20
// 0 0
// 输出例子：
// 6
// 30

#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        if(a==0 && b==0) return 0;
        cout << a + b << endl;
    }
}
// 64 位输出请用 printf("%lld")